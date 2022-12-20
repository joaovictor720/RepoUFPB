import java.io.*;
import java.net.Socket;

public class ProtocolClient {

	public static void main(String[] args) throws IOException {
		Socket s = new Socket("localhost", 4444);
		DataInputStream in = new DataInputStream(s.getInputStream());
		DataOutputStream out = new DataOutputStream(s.getOutputStream());
		BufferedReader stdIn = new BufferedReader(new InputStreamReader(System.in));
		
		while (true) {
			String fromUser = stdIn.readLine();
			out.writeUTF(fromUser);
			System.out.println(in.readUTF());
			if (fromUser.equals("Bye"))
				break;
		}
		
		stdIn.close();
		in.close();
		out.close();
		s.close();
	}

}
