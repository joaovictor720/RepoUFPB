import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

public class ProtocolServer {

	public static void main(String[] args) throws IOException {
		String fromClient;
		Protocol protocol = new Protocol();
		
		ServerSocket ss = new ServerSocket(4444);
		while (true) {
			Socket nsock = ss.accept();
			DataInputStream in = new DataInputStream(nsock.getInputStream());
			DataOutputStream out = new DataOutputStream(nsock.getOutputStream());
			
			while (true) {
				fromClient = in.readUTF();
				out.writeUTF(protocol.processLine(fromClient));
				
				if (fromClient.equals("Bye")) 
					break;
			}
			
			in.close();
			out.close();
			nsock.close();
		}
		
		//ss.close();
	}

}
