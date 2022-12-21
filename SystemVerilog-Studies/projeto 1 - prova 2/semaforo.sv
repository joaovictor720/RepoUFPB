module semaforo(input clk, modo, reset, output verdeA, verdeB, amareloA, amareloB, vermelhoA, vermelhoB);

parameter dia0 = 0, dia1 = 1, dia2 = 2, dia3 = 3, noite0 = 4, noite1 = 5;

logic [2:0] estado_atual;
logic [2:0] cont_clk;

always_comb begin

	case(estado_atual)
		
		dia0: 
		begin 
			{vermelhoA, amareloA, verdeA} = 3'b001;
			{vermelhoB, amareloB, verdeB} = 3'b100;
		end
		
		dia1: 
		begin 
			{vermelhoA, amareloA, verdeA} = 3'b010;
			{vermelhoB, amareloB, verdeB} = 3'b100;
		end
		
		dia2: 
		begin 
			{vermelhoA, amareloA, verdeA} = 3'b100;
			{vermelhoB, amareloB, verdeB} = 3'b001;
		end
				
		dia3: 
		begin 
			{vermelhoA, amareloA, verdeA} = 3'b100;
			{vermelhoB, amareloB, verdeB} = 3'b010;
		end
				
		noite0: 
		begin 
			{vermelhoA, amareloA, verdeA} = 3'b010;
			{vermelhoB, amareloB, verdeB} = 3'b010;
		end
				
		noite1: 
		begin 
			{vermelhoA, amareloA, verdeA} = 3'b000;
			{vermelhoB, amareloB, verdeB} = 3'b000;
		end
		
		default: 
		begin 
			{vermelhoA, amareloA, verdeA} = 3'b001;
			{vermelhoB, amareloB, verdeB} = 3'b100;
		end
		
	endcase
	
end

always_ff @(posedge clk, negedge reset) begin

	if (~reset)
		estado_atual <= dia0;
	else begin
		
		if (modo == 1) begin
			
			case (estado_atual)
			
				noite0:
					estado_atual <= noite1;
					
				noite1:
					estado_atual <= noite0;
					
				default:
					estado_atual <= noite0;
				
			endcase
			
		end
		else begin
			cont_clk = cont_clk + 3'b001;

			case (estado_atual)
				
				dia0:
				begin
					if (cont_clk == 3'd4) begin
						estado_atual <= dia1;
						cont_clk = 0;
					end
					else
						estado_atual <= estado_atual;
				end
				
				dia1:
				begin
					if (cont_clk == 3'd1) begin
						estado_atual <= dia2;
						cont_clk = 0;
					end
					else
						estado_atual <= estado_atual;
				end
				
				dia2:
				begin
					if (cont_clk == 3'd3) begin
						estado_atual <= dia3;
						cont_clk = 0;
					end
					else
						estado_atual <= estado_atual;
				end
				
				dia3:
				begin
					if (cont_clk == 3'd1) begin
						estado_atual <= dia0;
						cont_clk = 0;
					end
					else
						estado_atual <= estado_atual;
				end
				
				default:
					estado_atual <= dia0;
			
			endcase
		
		end
		
	end
		
end

endmodule
