short() { return "A dented old bucket <empty>"; }

long(str) {
	write("The bucket is old and a bit dented.\n"+
		"It is made of some metal, perhaps iron.\n"+
		"There are some small holes on the bucket\n"+
		"but it could still hold a few liters of\n"+
		"liquid. It is empty.\n");
	return;
}

id(str) { return str == "bucket" || str == "bucket_e"; }

get() {
    return 1;
}

query_weight() {
  return 200;
}