su dung HSI 8Mhz lam SYSCLK(Clock he thong):
Cac buoc khoi tao ngat ngoai cho EXTI:
	->tim ten ngat trong file startup_stm32f051.s
	->copy ten ham do vao file main.c(khi ngat xay ra chuong trinh se nhay vao ham nay thuc hien lenh)
	->thiet lap bit mask cho ngat EXTI(IMR)
	->cai dat suon bat ngat(RTST,FTSR)
	->Cai dat muxing de chon PinA chan 0(SYSCFG_EXTICR1)
	->thiet lap muc uu tien trog NVIC(NVIC_PRI)
	->enable ngat trong NVIC(NVIC_ISER)
	-> bat ngat toan cuc(__asm("cpsie i");)
note:
	khi ra khoi ngat phai xoa co ngat trong NVIC(NVIC_ICPR) va EXTI(EXTI_PR)
	