short() { return "A dented old bucket <full>"; }

long(str) {
	write("The bucket is old and a bit dented.\n"+
		"It is made of some metal, perhaps iron.\n"+
		"There are some small holes on the bucket\n"+
		"but it could still hold a few liters of\n"+
		"liquid. It is full of water.\n");
	return;
}

id(str) { return str == "bucket" || str == "bucket_f"; }

get() {
    return 1;
}

query_weight() {
  return 700;
}