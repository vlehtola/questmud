int temp;

start() {
	temp = time();
shadow(this_player(),1);
}

idle() {
int i;
i = time() - temp;
return i;
}