inherit "obj/monster";

int depressed=1;

reset(arg) {
    string chat_str, a_chat_str;
    object money, weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(30+random(3));
    set_gender(1);
    set_race("human");
    set_name("plainsman");
    set_alias("man");
    set_short("A sleepy plainsman");
    set_long	(
	"A grubby plainsman, sitting in a corner, snoring loudly. He is\n"+
	"clad in dirty old clothes and is probably part of some nomadic\n"+
	"tribe.\n"
		);

    set_al(1);
    set_aggressive(0);
    set_move_at_random(0);
        if (!chat_str) {
 chat_str = allocate(4);
 chat_str[0] ="Plainsman sighs in his sleep 'Damn monkey!'\n";
 chat_str[1] ="The plainsman snores loudly.\n";
 chat_str[2] ="The plainsman smiles as something pleasant happens in his sleep...\n";
 chat_str[3] ="Plainsman yell in his sleep 'It's a SNAAKE!!! ITS A SNAAAKE'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
a_chat_str[0] = "Plainsman yells 'NEVER wake me in my sleep!'\n";
    }
    load_chat(10, chat_str);
    load_a_chat(20, a_chat_str);

}
