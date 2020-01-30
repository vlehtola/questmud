#include <ansi.h>

inherit "obj/armour";
status i;

void start() {
  if(i) {
    set_class(9);
    set_sub_type("plate mail");
    set_name("mail");
    set_alias("plate");
    set_short("Mirror plate mail of gods <"+sprintf("%c",27)+"[1;1;30m"+"Dark aura"+OFF+">");
    set_long("This shining piece of armour reflects all the incoming\n"+
             "light in colours of the whole spectre. You also sense\n"+
             "a powerful aura around the plate mail. The handwork\n"+
             "seems to be ancient and it is said that Chaos himself\n"+
             "forged this magnificent piece of art in the volcano of\n"+
             "time. There are some runes embedded on the back of the\n"+
             "armour, the runes say '.gnisselb ym eviecer tlahs uoht\n"+
             "dna em pihsroW'");

    clear_stats();
    set_stats("str", 10);
    set_stats("con", 30);
    set_stats("dex", 9);
    set_stats("spr", 15);
    set_resists("fire", 10);
   
    return;
}
 else {
    set_class(9);
    set_sub_type("plate mail");
    set_name("mail");
    set_alias("plate");
    set_short("Mirror plate mail of gods <"+BOLD+"Light aura"+OFF+">");
    set_long("This shining piece of armour reflects all the incoming\n"+
             "light in colours of the whole spectre. You also sense\n"+
             "a powerful aura around the plate mail. The handwork\n"+
             "seems to be ancient and it is said that Chaos himself\n"+
             "forged this magnificent piece of art in the volcano of\n"+
             "time. There are some runes embedded on the back of the\n"+
             "armour, the runes say 'Worship me and thou shalt receive\n"+
             "my blessing'");

    clear_stats();
    set_stats("str", 1);
    set_stats("con", 10);
    set_stats("dex", 2);
    set_stats("spr", 3);
    set_resists("fire", 4);

  }
  return;
}

void init() {
  ::init();
  add_action("chaos", "worship"); 
}

status chaos(string str) {
 if(str=="chaos") {
    if(i == 0) {
      i = 1;
      write("The runes start transforming and the armour starts to glow with dark force\n");
      
    }
    else {
      i = 0;
      write ("The runes start transforming and the armour loses some of it's strength\n"); }

    }
    start();
this_player()->update_stats();
    return 1;
}
