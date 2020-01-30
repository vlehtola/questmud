/* Scroll makers can only have max 10 scroll */

mapping makers;
reset(arg) {
	if(arg) return;
	makers = ([ ]);
}

mapping query_makers() {
	return makers;
}

query_maker(string str) {
	return makers[str];
}

add_maker(string str) {
	makers[str] += 1;
}

reduce_maker(string str) {
	makers[str] -= 1;
}
