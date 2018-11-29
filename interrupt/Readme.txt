sử dụng HSE 8MHz làm SYSLCK
Các bước khởi tạo cho ngắt ngoài EXTI:
	->tìm tên ngắt trong file startup_stm32f051.s
	->copy tên hàm đó vào file main.c(khi có ngắt chương trình sẽ nhảy vào hàm này để thực hiện)
	->thiết lập bít mask cho EXTI(IMR)
	->cài đặt sườn bắt ngắt(RTST,FTSR)
	->cài đặt bộ muxing chọn PinA chan 0(SYSCFG_EXTICR1)
	->thiết lập mức ưu tiên  NVIC(NVIC_PRI)
	->enable ngắt trong NVIC(NVIC_ISER)
	-> bật ngắt toàn cục(__asm("cpsie i");)
note:
	khi ra khỏi ngắt cần xóa cờ ngắt NVIC(NVIC_ICPR) va EXTI(EXTI_PR)
	