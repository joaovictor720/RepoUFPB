module comparador(input [7:0] x, y, output maior, menor, igual);

/* FLUXO DE DADOS

assign maior = (x > y);

assign igual = (x == y);

assign menor = (x < y);*/

always @(x, y) begin

if (x > y)
	begin
		maior = 1;
		igual = 0;
		menor = 0;
	end
else if (x == y)
	begin
		maior = 0;
		igual = 1;
		menor = 0;
	end
else if (x < y)
	begin
		maior = 0;
		igual = 0;
		menor = 1;
	end

end

endmodule
