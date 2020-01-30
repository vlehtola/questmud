short() { return "A letter"; }

long(str) {
        write("Dear August, thank you for your letters so far,\n"+
        "but we must stop doing this or your wife might\n"+
        "find out about us and it might ruin this whole\n"+
        "kingdom. I don't know if you ever receive this\n"+
        "letter because I gave it to some strange looking\n"+
        "man to deliver... I hope you get this and understand\n"+
        "my point... -With love Susan-\n");
        return;
}

id(str) { return str == "letter"; }

get() {
    return 1;
}

query_weight() {
  return 10;
}
