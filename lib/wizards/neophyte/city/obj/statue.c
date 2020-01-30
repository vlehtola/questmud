short() { return "A large stone statue"; }

long(str) {
    write("The statue stands on a large pedestal and it is carved\n"+
          "from huge stone boulder. It looks like a large sailor\n"+
          "man, with a scrull wielded its right hand and fishing rod\n"+
          "in left. A large sign is attached to pedestal without\n"+
          "any text written.\n");
    return;
}

id(str) { return str == "statue"; }

get(str) {
    if (str == "statue") {
        write("You can't take the statue.\n");
        return 0;
    }
    return 0;
}

init() {
	add_action("read", "read");
}
read(str) {
	if(str == "sign") { write("The sign read: 'Nothing.'\n");  return 1; }
}
