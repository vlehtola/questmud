short() { return "Lister"; }
long() { write(short() + "\n"); }
id(str) { if (str == "lister") { return 1; } }

init() {
   add_action("update","update");
}

update(str) {
   string seko;
   int skitso;
   if (!str) { return; }
   if (sscanf(str, "%s %d", seko,skitso) != 2) {
	return;
   }
   find_object("/obj/list")->update_list(seko,skitso);
   write("Trying to.\n");
   return 1;
}
