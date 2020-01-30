short() { return "Exp checker"; }

id(str) { if (str == "checker") { return 1; } }

get() { return 1; }

long() { 
   write("Use 'check' to use it\n");
}

init() {
   add_action("check","check");
}

check(str) {
   object ob;
   if (!str) { write("Check who?\n"); return 1; }
   ob = present(str);
   if (!ob) { write("No " + str + " here.\n"); return 1; }
   write("Total exp: " + ob->query_worth() + "\n");
   return 1;
}
