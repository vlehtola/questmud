inherit "obj/armour";

int animal;

init() {
   ::init();
   add_action("transform", "transform");
}

reset(arg) {
   ::reset(arg);
   set_name("wound");
   set_short("A rotting wound");
   set_long("As you look at the wound, you remember the pain you\n" +
            "had to go through when you joined the creatures of the night.\n");
   set_weight(0);
   set_value(0);
   set_ac(0);
   set_slot("back of neck");
}

transform(str) {

animal=random(6);
if (animal == 0) {
say(call_other(this_player(), "query_name") + " tries to transform, but fails miserably.\n");
write("You fail to transform.\n");
return 1;

}
if (animal == 1) {
write("You transform into a MOUSE!\n");
say("You fall down laughing as " + call_other(this_player(), "query_name") + " transforms into a MOUSE!\n");
return 1;
                     }
if (animal == 2) {
write("You transform to a CAT!\n");
say(call_other(this_player(), "query_name") + " transforms into a CAT!\n");
return 1;
                     }
if (animal == 3) {
write("You transform to a WOLF!\n");
say(call_other(this_player(), "query_name") + " transforms into a WOLF!\n");
return 1;
                     }
if (animal == 4) {
write("You transform to a HUGE RAGING WOLF!\n");
say(call_other(this_player(), "query_name") + " transforms into a RAGING WOLF!\n");
return 1;
                     }
if (animal == 5) {
write("You transform to a TERRIBLE BEAST!\n");
say("You gleem in TERROR as " + call_other(this_player(), "query_name") + " transforms into a TERRIBLE BEAST!\n");
return 1;
                     }
}

