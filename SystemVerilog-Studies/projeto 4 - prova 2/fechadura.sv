module fechadura(input clk, inserir, output logic led_verde, led_vermelho);

int cont_dig = 5;
logic [1:0] estado_atual;
logic [5:0] senha;

parameter digitando = 0, aberto = 1, erro = 2;

always_comb begin
	
	case (estado_atual)
	
		digitando:
		begin
			led_verde <= 0;
			led_vermelho <= 0;
		end
		
		aberto:
		begin
			led_verde <= 1;
			led_vermelho <= 0;
		end
		
		erro:
		begin
			led_verde <= 0;
			led_vermelho <= 1;
		end
		
	endcase
	
end

always_ff @(posedge clk) begin

	case (estado_atual)
		
		digitando:
		begin
			
			senha[cont_dig] <= inserir;
			
			if (cont_dig >= 0)
			
				cont_dig--;
			
			else if (senha == 6'b101100) begin
	
				estado_atual <= aberto;
		
			end
			else begin
	
				estado_atual <= erro;
				
			end
			
		end
		
		default:
		begin
			
			cont_dig = 5;
			estado_atual <= digitando;
			
		end
	
	endcase

end

endmodule
