USART (Universal synchronous asynchronous receiver transmitter)

A. Danh s�nh nh?ng module li�n quan:
- Clock (RCC):
	-> T�nh to�n gi� tr? clock ch�nh x�c c?p cho USART1
	-> Enable clock gate cho UART module
- GPIO:
	-> Khoi tao mode cho chan Tx/Rx
- USART:
	-> kh?i t?o module.
	-> vi?t h�m truy?n/nh?n d? li?u
- NVIC:
	-> kh?i t?o v� cho ph�p ng?t c?a USART1
	-> interrupt handler

B. USART:
1. Khoi tao:
- Disable USART module -> USART_CR1[UE] = 0;
- Data = 8 bits -> USART_CR1[M1:M0]
- Parity = none -> USART_CR1[PCE]
- Stop = 1 bit  -> USART_CR2[STOP]
- Baudrate = 9600 bps -> thi?t l?p oversample1 USART_CR1[OVER8] = 16 bits
- Ghi he so chia vao thanh ghi USART[BRR]
- Enable USART module -> USART_CR1[UE] = 1;
- Enable Tx -> USART_CR1[TE]
- Enable Rx -> USART_CR1[RE]

2. Qu� tr�nh truy?n d? li?u:
- C?n ki?m tra c? USART_ISR[TXE]
	-> N?u USART_ISR[TXE] = 1 -> ti?n h�nh ghi d? li?u v�o USART_TDR = <data> (luu � l� ghi 1 byte d? li?u)
	-> N?u USART_ISR[TXE] = 0 -> kh�ng ghi d? li?u v�o USART_TDR
- Truy?n dc d? li?u

3. Qu� tr�nh nh?n d? li?u:
- C?n ki?m tra c? USART_ISR[RXNE]
- N?u USART_ISR[RXNE] = 1 -> ti?n h�nh d?c d? li?u tr�n thanh ghi USART_RDR[8:0]
- X�a c? ng?t USART_ISR[RXNE] b?ng vi?c d?c d? li?u tren USART_RDR ho?c ghi 1 t?i b�t USART_RQR[RXFRQ]