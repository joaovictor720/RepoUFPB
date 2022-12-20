import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.io.*;

public class ClientUDP {

	public static void main(String[] args) throws IOException{
		DatagramPacket in, out;
		DatagramSocket s = new DatagramSocket();
		
		byte[] outbuf = new String("Hello Server").getBytes();
		InetAddress server = InetAddress.getByName("localhost");
		out = new DatagramPacket(outbuf, outbuf.length, server, 4444);
		s.send(out);
		
		byte[] inbuf = new byte[256];
		in = new DatagramPacket(inbuf, inbuf.length);
		s.receive(in);
		
		System.out.println(new String(in.getData(), 0, in.getLength() ) );
		
		s.close();
	}

}
