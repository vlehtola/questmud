
inherit "room/room";
reset(arg) {
if(arg) return;
add_exit("inn","/world/city/inn");
 add_exit("cs","/world/city/cs");
short_desc = "Punishments Workroom";
long_desc = "This is the place where the greatest of them all gather to discuss\n"+
"about matters of wizarhood.\n";
}
