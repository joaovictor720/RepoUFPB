import java.io.*;
import java.net.Socket;

public class SocketHandler implements Runnable {
	Socket s;
	Protocol protocol = new Protocol();
	
	public SocketHandler(Socket nsock) {
		this.s = nsock;
	}
	
	public void run() {
		try {
			DataInputStream in = new DataInputStream(s.getInputStream());
			DataOutputStream out = new DataOutputStream(s.getOutputStream());
			
			while (true) {
				String fromClient = in.readUTF();
				out.writeUTF(protocol.processLine(fromClient));
				
				if (fromClient.equals("Bye")) 
					break;
			}
		
		
			in.close();
			out.close();
			s.close();
			
		} catch (IOException ioe) {
			ioe.printStackTrace();
		}
	}
}
