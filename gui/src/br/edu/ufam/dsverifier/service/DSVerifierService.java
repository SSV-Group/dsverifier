package br.edu.ufam.dsverifier.service;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.concurrent.TimeUnit;

import br.edu.ufam.dsverifier.domain.Verification;
import br.edu.ufam.dsverifier.domain.enums.VerificationStatus;
import br.edu.ufam.dsverifier.util.DSVerifierUtils;

public class DSVerifierService {

	public static final String ESBMC_EXECUTABLE = "esbmc";
	public static final String ESBMC_PARAMETERS = "-DSVERIFIER --no-div-by-zero-check --no-bounds-check --no-pointer-check --boolector";
	
	private static DSVerifierService instance;
	
	private DSVerifierService(){		
	}
	
	public static DSVerifierService getInstance(){		
		if (instance == null){
			instance = new DSVerifierService();
		}
		return instance;				
	}
	
	public void callDSVerifier(Verification verification) throws Exception {	
		File verificationFile = verification.getFile();
		String verificationFilePath = verificationFile.getAbsolutePath();
		StringBuilder commandLine = new StringBuilder(ESBMC_EXECUTABLE + " " + verificationFilePath + "  " + ESBMC_PARAMETERS);
		
		/* include the property */
		commandLine.append(" -DPROPERTY=" + verification.getProperty());
		/* include the realization */
		commandLine.append(" -DREALIZATION=" + verification.getImplementation().getRealization());	
		/* include x size */
		commandLine.append(" -DX_SIZE=" + verification.getBound());	

		
		System.out.println("COMMAND LINE: " + commandLine.toString());
		
		long initialTime = System.nanoTime();  
		String output = DSVerifierUtils.getInstance().callCommandLine(commandLine.toString());
		long finalTime = System.nanoTime();  
		long seconds = TimeUnit.SECONDS.convert(finalTime - initialTime, TimeUnit.NANOSECONDS);
		
		verification.setTime(seconds);
		verification.setOutput(output);
		if (output.indexOf("VERIFICATION FAILED") != -1){
			verification.setStatus(VerificationStatus.VERIFICATION_FAILED);
		}else if (output.indexOf("VERIFICATION SUCCESSFUL") != -1){
			verification.setStatus(VerificationStatus.VERIFICATION_SUCCESSFUL);
		}else{
			verification.setStatus(VerificationStatus.UNKNOWN);
		}
	}
	
	public String prepareCommandLine(Verification verification){
		String commandLine = ESBMC_EXECUTABLE + " " + ESBMC_PARAMETERS + " ";
		return commandLine;		
	}	
	
	public void generateVerificationFile(Verification verification) throws IOException{
		
		StringBuilder content = new StringBuilder();			
		content.append("#include<dsverifier.h>\n\n");
		content.append("digital_system ds = {\n");
		content.append("\t.a = " + verification.getDigitalSystem().getDenominator() + ",\n");
		content.append("\t.a_size = " + verification.getDigitalSystem().getDenominatorSize() + ",\n");
		content.append("\t.b = " + verification.getDigitalSystem().getNumerator() + ",\n");
		content.append("\t.b_size = " + verification.getDigitalSystem().getNumeratorSize() + "\n");
		content.append("};\n");
		
		content.append("\nimplementation impl = {\n");
		content.append("\t.int_bits = " + verification.getImplementation().getIntegerBits() + ",\n");
		content.append("\t.frac_bits = " + verification.getImplementation().getPrecisionBits() + ",\n");
		content.append("\t.min = " + verification.getImplementation().getMinimum() + ",\n");
		content.append("\t.max = " + verification.getImplementation().getMaximum() + ",\n");
		content.append("\t.scale = " + verification.getImplementation().getScale() + "");

		if (verification.getImplementation().getDelta() != null){
			content.append(",\n\t.delta = " + verification.getImplementation().getDelta() + "");
		}
		
		content.append("\n};\n");
		
		/* create file content */
		verification.setFileContent(content.toString());		
		File verificationTmpFile = File.createTempFile("dsverifier", ".c");
		verification.setFile(verificationTmpFile);
		
		/* write in temporary file */
		FileWriter fileWriter = new FileWriter(verificationTmpFile.getAbsoluteFile());
		BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
		bufferedWriter.write(content.toString());
		bufferedWriter.close();		
		
	}
	
}