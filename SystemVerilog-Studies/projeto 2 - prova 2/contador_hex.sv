module contador_hex(input clk, modo, reset,
							output logic seg1, seg2, seg3, seg4, seg5, seg6, seg7);

parameter dois = 0, cinco = 1, sete = 2, tres = 3, A = 4, E = 5, oito = 6, zero = 7,
			b = 8, quatro = 9, seis = 10, d = 11, F = 12, um = 13, C = 14, nove = 15;
			
logic [3:0] contador;

/**
Modelo do display de 7 segmentos:

 /-seg1-\
 | 	  |
seg6	seg2
 |	     |
  -seg7-
 |		  |
seg5	seg3
 |		  |
 \-seg4-/
 
*/

// as letras B e D maiúsculas coincidiriam com 8 e 0 num display de 7 segmentos,
// então pra não aumentar a quantidade de segmentos, escolheu-se escrevê-las em minúsculo b e d

always_comb begin

	case(contador)
	
		dois: 	begin seg1 = 1; seg2 = 1; seg3 = 0; seg4 = 1; seg5 = 1; seg6 = 0; seg7 = 1; end
		cinco: 	begin seg1 = 1; seg2 = 0; seg3 = 1; seg4 = 1; seg5 = 0; seg6 = 1; seg7 = 1; end
		sete: 	begin seg1 = 1; seg2 = 1; seg3 = 1; seg4 = 0; seg5 = 0; seg6 = 0; seg7 = 0; end
		tres: 	begin seg1 = 1; seg2 = 1; seg3 = 1; seg4 = 1; seg5 = 0; seg6 = 0; seg7 = 1; end
		
		A: 		begin seg1 = 1; seg2 = 1; seg3 = 1; seg4 = 0; seg5 = 1; seg6 = 1; seg7 = 1; end
		E: 		begin seg1 = 1; seg2 = 0; seg3 = 0; seg4 = 1; seg5 = 1; seg6 = 1; seg7 = 1; end
		oito: 	begin seg1 = 1; seg2 = 1; seg3 = 1; seg4 = 1; seg5 = 1; seg6 = 1; seg7 = 1; end
		zero: 	begin seg1 = 1; seg2 = 1; seg3 = 1; seg4 = 1; seg5 = 1; seg6 = 1; seg7 = 0; end
		
		b: 		begin seg1 = 0; seg2 = 0; seg3 = 1; seg4 = 1; seg5 = 1; seg6 = 1; seg7 = 1; end
		quatro: 	begin seg1 = 0; seg2 = 1; seg3 = 1; seg4 = 0; seg5 = 0; seg6 = 1; seg7 = 1; end
		seis: 	begin seg1 = 1; seg2 = 0; seg3 = 1; seg4 = 1; seg5 = 1; seg6 = 1; seg7 = 1; end
		d: 		begin seg1 = 1; seg2 = 1; seg3 = 1; seg4 = 1; seg5 = 1; seg6 = 0; seg7 = 1; end
		
		F: 		begin seg1 = 1; seg2 = 0; seg3 = 0; seg4 = 0; seg5 = 1; seg6 = 1; seg7 = 1; end
		um: 		begin seg1 = 0; seg2 = 1; seg3 = 1; seg4 = 0; seg5 = 0; seg6 = 0; seg7 = 0; end
		C: 		begin seg1 = 1; seg2 = 0; seg3 = 0; seg4 = 1; seg5 = 1; seg6 = 1; seg7 = 0; end
		nove: 	begin seg1 = 1; seg2 = 1; seg3 = 1; seg4 = 0; seg5 = 0; seg6 = 1; seg7 = 1; end
		
		default: begin seg1 = 0; seg2 = 0; seg3 = 0; seg4 = 0; seg5 = 0; seg6 = 0; seg7 = 0; end
		
	endcase
	
end

always_ff @(posedge clk, negedge reset) begin

	if (~reset)
	
		contador <= dois;
		
	else case (contador)
	
		dois: 
		begin
			if (modo == 0) begin
				contador <= cinco;
			end
			else begin
				contador <= nove;
			end
		end
		
		cinco: 
		begin	
			if (modo == 0) begin
				contador <= sete;
			end
			else begin
				contador <= dois;
			end
		end
		
		sete: 
		begin
			
			if (modo == 0) begin
				contador <= tres;
			end
			else begin
				contador <= cinco;
			end
		end
		
		tres: 
		begin			
			if (modo == 0) begin
				contador <= A;
			end
			else begin
				contador <= sete;
			end
		end
		
		A: 
		begin		
			if (modo == 0) begin
				contador <= E;
			end
			else begin
				contador <= tres;
			end
		end
		
		E: 
		begin	
			if (modo == 0) begin
				contador <= oito;
			end
			else begin
				contador <= A;
			end
		end
		
		oito: 
		begin
			if (modo == 0) begin
				contador <= zero;
			end
			else begin
				contador <= E;
			end
		end
		
		zero: 
		begin
			if (modo == 0) begin
				contador <= b;
			end
			else begin
				contador <= oito;
			end
		end
		
		b: 
		begin
			if (modo == 0) begin
				contador <= quatro;
			end
			else begin
				contador <= zero;
			end
		end
		
		quatro: 
		begin
			if (modo == 0) begin
				contador <= seis;
			end
			else begin
				contador <= b;
			end
		end

		seis: 
		begin
			if (modo == 0) begin
				contador <= d;
			end
			else begin
				contador <= quatro;
			end
		end
		
		d: 
		begin	
			if (modo == 0) begin
				contador <= F;
			end
			else begin
				contador <= seis;
			end
		end
		
		F: 
		begin				
			if (modo == 0) begin
				contador <= um;
			end
			else begin
				contador <= d;
			end
		end
		
		um: 
		begin
			if (modo == 0) begin
				contador <= C;
			end
			else begin
				contador <= F;
			end
		end
		
		C: 
		begin
			if (modo == 0) begin
				contador <= nove;
			end
			else begin
				contador <= um;
			end
		end
		
		nove: 
		begin	
			if (modo == 0) begin
				contador <= dois;
			end
			else begin
				contador <= C;
			end
		end
		
		default: 
		begin
			contador <= dois;
		end
		
	endcase

end

endmodule
