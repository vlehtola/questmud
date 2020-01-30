cmd_ask(object who, string what) {
        string asia;
        object target, ftgt;
        asia = what;
        if(!who) {
                        write("Usage: 'ask <monster> about <something>'\n");
                        return 1;
                }
                if (sscanf(who, "%s about %s", who, asia) == 2) {
                        target = present(who, this_player());
                        if(!target) target = present(who, environment(this_player()));
                        if(!target) {
                                write("There is no " + who + " here.\n");
                                return 1;
                        }
                        if(!asia) {
                                write("Usage: 'ask <monster> about <something>'\n");
                                return 1;
                        }
                        if(!living(target) || target->query_animal()) {
                                write("You can't ask anything from that.\n");
                                return 1;
                        }
                        if(!target->query_npc()) {
                                write("You can't ask anything from that.\n");
                                return 1;
                        }
                        if(!function_exists("ask_question", target)) {
                                say(who+ " shrugs " + target->query_possessive() + " shoulders.\n");
                                write(who+ " shrugs " + target->query_possessive() + " shoulders.\n");
                                return 1;
                        }
                                                write("You ask " + who + " about " + asia + ".\n");
                                                say(this_player()->query_name()+ " ask something from the " + who + ".\n");
                                                target->ask_question(asia);
                                                return 1;
                                        }
                                                write("Usage: 'ask <monster> about <something>'\n");
                                                return 1;
}
