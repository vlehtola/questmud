inherit "obj/monster";
reset(arg) {
object armour;
::reset(arg);
if(arg) { return; }
set_level(30);
set_name("bear");
set_short("A massive grizzly bear");
set_long("The massive grizzly bear has a strong muscles in its huge paws.\n"+
         "Its small eyes, short, furry tail and long ears gives it a teddy\n"+
         "bear look. The bear has a thick, furry and greyish bearskin,\n"+
         "giving it a harmless look.\n");
set_al(20);
set_aggressive(0);
set_gender(0);
set_animal(1);
set_str(180);
set_skill("inner strength", 100);

    armour = clone_object("/wizards/irmeli/ff/eq/bearskin.c");
    move_object(armour,this_object());
}
