#include <ansi.h>

inherit "obj/weapon";

start() {
  set_class(9);
  set_sub_type("great axe");
  set_name("fury");
  set_alias("axe");
  set_short("A magnificent axe called '"+RED_F+"Wiz-force!"+OFF+"'");
  set_long("This massive great axe was forged by a most curious\n"+
           "half-elven being named Chao'en. He lost his parents\n"+
           "at young age when his home village was raided by goblins.\n"+
           "He was able to hide from the furious horde, but would've\n"+
	   "propably starved to death if it wasn't for a Dwarven smith\n"+
           "whose name has since faded from history. He raised Chao'en\n"+
           "and accepted him as his apprentice. Chao'en never recovered\n"+
           "fully from his loss of parents, and he single-mindedly\n"+
	   "devoted his to the arts of smithing, he was barely fully grown\n"+
           "when he was just as good a smith as his mentor, if not better.\n"+
           "But a disaster hit, the anonymous dwarven smith, his closest thing to\n"+
           "a relative was murdered by a frenzied customer after a quarrel\n"+
           "about the cost of repairing his long sword. That is when Chao'en\n"+
           "lost all that was left of his mind. He rummaged through the contents\n"+
           "of his deceased mentor's chests and collected a mix of strage metals\n"+
           "he had acquired while traveling around the known world. Bare handed,\n"+
           "without tongs he furiously hammered the metals into the form\n"+
	   "of a huge axe. With it he was to have his revenge on all living...\n"+
	   "However, it was not to be, he was later found by a villager who\n"+
           "brought his plow to be repaired, he took the axe, not knowing it\n"+
           "had the very essence of Chao'en poured into it. His name was rumoured\n"+
           "to be Gorgola, though few know of his current whereabouts..");
    set_stats("damage",10);
    set_stats("hit",10);

}

hit() {
  if(!wielded_by || !wielded_by->query_attack()) return;
  if(random(7) != 0) return;
  tell_room(environment(wielded_by), "Suddenly some lava"+
" bursts out the axe and hits "+wielded_by->query_attack()->query_name()+".\n");
  wielded_by->query_attack()->hit_with_spell(random(300)+800000,"acid"); 
  return 1;
}
