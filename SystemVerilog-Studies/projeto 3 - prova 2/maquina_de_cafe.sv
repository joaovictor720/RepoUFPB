module maquina_de_cafe(input [1:0] tipo, input clk, reset, output logic C, L, F);

int qnt_cafe = 0 , qnt_leite = 0; 

logic [1:0] estado_atual;
	
parameter enchendo_cafe = 0, enchendo_leite = 1, pronto = 2, espera = 3;

always_comb begin
	
	case (estado_atual)
		 
		 enchendo_cafe:
		 begin
			C = 1;
			L = 0;
			F = 0;
		 end
		 
		 enchendo_leite:
		 begin
			C = 0;
			L = 1;
			F = 0;
		 end
		 
		 pronto:
		 begin
			C = 0;
			L = 0;
			F = 1;
		 end
		 
		 espera:
		 begin
			C = 0;
			L = 0;
			F = 0;
		 end
		
	endcase

end

always_ff @(posedge clk, negedge reset) begin
	
	if (~reset)
		estado_atual <= espera;
	else
		case(estado_atual)
			
			enchendo_cafe:
			begin
				qnt_cafe += 25;
				
				if ( (tipo == 0) && (qnt_cafe == 50) )
					estado_atual <= pronto;
				
				if ( (tipo == 1) && (qnt_cafe == 100) )
					estado_atual <= pronto;
				
				if ( (tipo == 2) && (qnt_cafe == 50) )
					estado_atual <= enchendo_leite;
			end
			
			enchendo_leite:
			begin
				qnt_leite += 25;
				
				if (qnt_leite == 50)
					estado_atual <= pronto;
			end
			
			pronto:
			begin
				qnt_cafe = 0;
				qnt_leite = 0;
				estado_atual <= espera;
			end
			
			espera:
			begin
				if (tipo == 3)
					estado_atual <= espera;
				else
					estado_atual <= enchendo_cafe;
			end

		endcase
	
end

endmodule
