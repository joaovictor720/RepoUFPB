import java.net.ServerSocket;
import java.net.Socket;
import java.util.concurrent.Executor;
import java.util.concurrent.Executors;
import java.io.*;

public class ConcurrentServer {

	public static void main(String[] args) throws IOException {
		Executor pool = Executors.newCachedThreadPool();
		ServerSocket ss = new ServerSocket(4444);
		
		while (true) {
			Socket nsock = ss.accept();
			pool.execute(new SocketHandler(nsock));
		}
	}

}
