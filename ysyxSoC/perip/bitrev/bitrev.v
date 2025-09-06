module bitrev (
  input  sck,
  input  ss,
  input  mosi,
  output reg miso
);
localparam IDLE = 2'b00;
localparam REV  = 2'b01;
localparam SEND = 2'b10;
reg [1:0] state;
reg [1:0] next_state;
reg [2:0] cnt;
reg [7:0] data_in;
always @(*) begin
	case (state)
		IDLE: begin
			if (ss == 1'b0) next_state = REV;
			else next_state = IDLE;
		end
		REV: begin
			if (cnt == 3'd7) next_state = SEND;
			else next_state = REV;
		end
		SEND: begin
			if (cnt == 3'd0) next_state = IDLE;
			else next_state = SEND;
		end
		default: next_state = IDLE;
	endcase
end
always @(posedge sck) begin
	state <= next_state;
end
always @(posedge sck) begin
	if(next_state == REV && state == IDLE) begin
		cnt <= 3'b000;
		data_in <= {data_in[6:0], mosi}; // Shift in data
	end else if (state == REV && next_state != SEND) begin
		cnt <= cnt + 1'b1;
		data_in <= {data_in[6:0], mosi}; // Shift in data
	end else if (state == REV && next_state == SEND) begin
		cnt <= cnt - 1'b1;
		miso <= data_in[cnt]; 
	end
	else if (state == SEND) begin
		cnt <= cnt - 1'b1;
		miso <= data_in[cnt]; 
	end else begin
		cnt <= 3'b000; // Reset counter on IDLE or SEND
		miso <= 1'b1;
	end
end


endmodule
