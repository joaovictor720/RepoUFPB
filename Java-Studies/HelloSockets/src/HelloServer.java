import java.net.ServerSocket;
import java.net.Socket;
import java.io.*;

public class HelloServer {

	public static void main(String[] args) throws IOException {
		ServerSocket s = new ServerSocket(4444);
		Socket ns = s.accept();
		DataInputStream in = new DataInputStream(ns.getInputStream());
		DataOutputStream out = new DataOutputStream(ns.getOutputStream());
		
		System.out.println(in.readUTF());
		out.writeUTF("Hello Client");
		
		in.close();
		out.close();
		ns.close();
		s.close();
	}

}
