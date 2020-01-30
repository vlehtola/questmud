short() { return "A rusty old lever"; }

long(str) {
    write("This is a rusty old lever. It is stuck in a big pile of\n"+
          "dust. You can't see where the lever ends but you might\n"+
          "be able to pull it.\n");
    return;
}

id(str) { return str == "lever"; }

get() {
    return 0;
}

query_weight() {
  return 100;
}
