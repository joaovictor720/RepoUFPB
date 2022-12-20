import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.io.*;

public class ServerUDP {

	public static void main(String[] args) throws IOException{
		DatagramPacket in, out;
		DatagramSocket s = new DatagramSocket(4444);
		
		byte[] inbuf = new byte[256];
		in = new DatagramPacket(inbuf, inbuf.length);
		s.receive(in);
		
		System.out.println(new String(in.getData(), 0, in.getLength() ) );
		
		InetAddress client = in.getAddress();
		int port = in.getPort();
		
		byte[] outbuf = new String("Hello Server").getBytes();
		out = new DatagramPacket(outbuf, outbuf.length, client, port);
		s.send(out);
		
		s.close();
	}
}
