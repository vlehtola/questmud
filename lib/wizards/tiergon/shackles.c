inherit "obj/armour";

start() {
set_slot("arms");
set_name("shackles");
set_short("Thick shackles");
set_long("HA HA HA");
set_value(0);
set_weight(100);
}

init() {
::init();
add_action("none","ed");
add_action("none","eval");
add_action("none","goto");
add_action("none","quit");
add_action("none","tell");
add_action("none","t");
add_action("none","ld");
add_action("none","destruct");
add_action("none","dest");
add_action("none","say");
add_action("none","channels");
add_action("none","shout");
add_action("none","north");
add_action("none","south");
add_action("none","east");
add_action("none","west");
add_action("none","cs");
add_action("none","out");
add_action("none","goin");
add_action("none","home");
add_action("none","inn");
add_action("none","fiz");
add_action("none","fin");
add_action("none","ghost");
add_action("none","newbie");
add_action("none","chat");
add_action("none","sales");
add_action("none","mud");
add_action("none","swe");
add_action("none","code");
add_action("none","alert");
add_action("none","wiz");
add_action("none","hockey");
add_action("none","drop");
add_action("none","get");
add_action("none","give");
add_action("none","cd");
add_action("none","ls");
add_action("none","more");
add_action("none","wanted");
add_action("none","echoto");
add_action("none","echo");
add_action("none","echoall");
add_action("hep","touch");
}

none() {
write("The shackles restrain you.\n");
return 1;
}

hep(str) {
if(!str) return 1;
if(str == "shackles") {write("The shackles turn to dust.\n");destruct(this_object());}
return 1;
}
