//To prevent abuse

mapping uses;

reset(arg) {
	if(arg) return;
	uses = ([]);
}

query_use(str) {
	return uses[str];
}

add_use(str) {
	if(!uses[str]) {
		uses += ([ (string)str: (int)1]);
		return 1;
	} else {
		uses[str]++;
	}
	return 1;
}
