import java.net.Socket;
import java.io.*;

public class HelloClient {

	public static void main(String[] args) throws IOException {
		Socket s = new Socket("localhost", 4444);
		DataInputStream in = new DataInputStream(s.getInputStream());
		DataOutputStream out = new DataOutputStream(s.getOutputStream());
		
		out.writeUTF("Hello Server");
		System.out.println(in.readUTF());
		
		in.close();
		out.close();
		s.close();
	}

}
