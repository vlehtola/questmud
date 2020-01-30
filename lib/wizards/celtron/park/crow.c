inherit "obj/monster";
object victim;

reset(arg) {
    int i;
    ::reset(arg);
    set_name("crow");
    i = random(2);
    if (i == 0) {
	set_short("A grey crow");
    	set_long("Crow looks hostile and evil. Somehow you feel that it doesn't like you.\n");
    }
    if (i == 1) {
        set_short("A black crow");
        set_long("Crow looks hostile and evil. Somehow you feel that it doesn't like you.\n");
    }
    set_level(2+i*2+random(1));
    set_aggressive(random(i));
    set_al(-10);
    set_animal(1);
    set_wc(4);
}







