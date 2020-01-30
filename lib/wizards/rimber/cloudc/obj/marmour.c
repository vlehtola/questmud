inherit "obj/armour";
int a;

start() {
 set_class(9);
 set_sub_type("scale mail");
 set_name("breastplate");
 set_alias("breastplate");
 set_short("Golden breastplate with silver straps");
 set_long("Jne.\n");
 if(a == 0) { set_stats("con", 14); }
 if(a == 1) { set_stats("wis", 14); }
}

init() {
 ::init();
 add_action("read", "read");
}

read(str) {
 if(str == "scribble") {
 switch(a) {
  case 0 : write("You read the scribble and the breastplate glows a while.\n");
   a = 1;
   reset();
   break;
  case 1 : write("You read the scribble and the breastplate glows a while.\n");
   a = 0;
   reset();
   break;
 }
 }
 else { write("Read what?"); }
 return 1;
}
