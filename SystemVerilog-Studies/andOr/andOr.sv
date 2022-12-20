module andOr(X, A, B, Out);

input X, A, B;
output Out;

assign Out = X ? (A&B) : (A|B);

endmodule
