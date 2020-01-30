short() { return "A clock showing the time"; }

long() {
    write("It shows:\n");
    write(ctime(time()) + ".\n");
}

get() { return 1; }

id(str) { return str == "watch" || str == "clock"; }
