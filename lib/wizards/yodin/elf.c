inherit "obj/monster";
reset(arg) {
int a;
a = random(3);
::reset(arg);
if (arg) return;
set_race("wood elf");
set_name("elf");
set_alias("elf");
set_dex(query_dex() + 200);
set_str(query_str() + 200);
switch(a) {

case 0 : set_level(46+random(5));
set_short("Wood elf inspecting the forest");
set_gender(1);
set_alt_name("elf");

break;
case 1 : set_level(40+random(3));
set_short("Elf dwelling in the forest");
set_gender(1);
set_alt_name("elf");

break;
case 2 : set_level(44+random(10));
set_short("Elf relaxing under the tree");
set_gender(0);
set_alt_name("elf");
break;
}
 set_long("Wood elf is here to relax and enjoying the beauty of.\n" +
          "the forest. Elf has handsome looking green shirt and green\n" +
          "trousers. He has long pointy ears and beautiful blond\n" +
          "hair. Elf seems to be aware about everybody and everything.\n");


 }