/* Modified for genders: padrone, Oct 22 1990 */
/* Additions and upgrades for soul.c completed on 22.6.1998 by Nalle */

object the_owner;
string cap_name;
string adverb;
string bodypart;

get() {
    the_owner = this_player();
    cap_name = call_other(this_player(), "query_name", 0);
    return 1;
}

drop() { return 1; }

id(str) { return str == "soul_object"; }

long() {
    write("It is transparent.\n");
}

ghost() {
    the_owner = this_player();
    cap_name = call_other(this_player(), "query_name", 0);
    return call_other(this_player(), "query_ghost");
}

init() {
    the_owner = this_player();
    cap_name = call_other(this_player(), "query_name", 0);
    add_action("emotes", "emotes");   
    add_action("adverbs", "adverbs"); 
    add_action("ack", "ack");
    add_action("agree", "agree");
    add_action("ah", "ah");
    add_action("apologize", "apologize");
    add_action("applaud", "applaud");
    add_action("argh", "argh");
    add_action("bark", "bark");
    add_action("beg", "beg");
    add_action("bleed", "bleed");
    add_action("blink", "blink");
    add_action("blush", "blush");
    add_action("boo", "boo");
    add_action("bore", "bore");
    add_action("bored", "bored");
    add_action("bounce", "bounce");
    add_action("bow", "bow");
    add_action("burp", "burp");
    add_action("cackle", "cackle");
    add_action("calculate", "calculate");
    add_action("caress", "caress");
    add_action("cheer", "cheer");
    add_action("chuckle", "chuckle");
    add_action("clap", "clap");
    add_action("click", "click");
    add_action("comfort", "comfort");
    add_action("confuse", "confuse");
    add_action("confused", "confused");
    add_action("contently", "contently");
    add_action("congratulate", "congratulate");
    add_action("cough", "cough");
    add_action("croak", "croak");
    add_action("cry", "cry");
    add_action("cuddle", "cuddle");
    add_action("curse", "curse");
    add_action("curtsey", "curtsey");
    add_action("dance", "dance");
    add_action("disagree", "disagree");
    add_action("dream", "dream");
    add_action("drool", "drool");
    add_action("eww", "eww");
    add_action("eep", "eep");
    add_action("excuse", "excuse");
    add_action("fart", "fart");
    add_action("fear", "fear");
    add_action("flex", "flex");
    add_action("flip", "flip");
    add_action("flirt", "flirt");
    add_action("fondle", "fondle");
    add_action("foretell", "foretell");
    add_action("freeze", "freeze");
    add_action("french", "french");
    add_action("frown", "frown");
    add_action("gasp", "gasp");
    add_action("giggle", "giggle");
    add_action("gigglesnort", "gigglesnort");
    add_action("glare", "glare");
    add_action("glug", "glug");
    add_action("greet", "greet");
    add_action("grin", "grin");
    add_action("groan", "groan");
    add_action("grope", "grope");
    add_action("growl", "growl");
    add_action("grr", "grr");
    add_action("gurgle", "gurgle");
    add_action("hail", "hail");
    add_action("heh", "heh");
    add_action("hiccup", "hiccup");
    add_action("hmm", "hmm");
    add_action("hmpf", "hmpf");  
    add_action("hmph", "hmph");
    add_action("hooray", "hooray");
    add_action("hug", "hug");
    add_action("hum", "hum");
    add_action("kick", "kick");
    add_action("kiss", "kiss");
    add_action("knee", "knee");
    add_action("laugh", "laugh");
    add_action("lick", "lick");
    add_action("love", "love");
    add_action("lust", "lust");
    add_action("mercy", "mercy");
    add_action("moan", "moan");
    add_action("mourn", "mourn");
    add_action("mrh", "mrh");
    add_action("muah", "muah");
    add_action("nibble", "nibble");
    add_action("nod", "nod");
    add_action("nodnod", "nodnod");
    add_action("observe", "observe");
    add_action("ooo", "ooo");
    add_action("oops", "oops");
    add_action("ouch", "ouch");
    add_action("pat", "pat");
    add_action("play", "play");
    add_action("poke", "poke");
    add_action("pout", "pout");
    add_action("puke", "puke");
    add_action("purr", "purr");
    add_action("puuh", "puuh");
    add_action("refuse", "refuse");
    add_action("ruffle", "ruffle");
    add_action("scare", "scare");
    add_action("scratch", "scratch");
    add_action("scream", "scream");
    add_action("shake", "shake");
    add_action("shiver", "shiver");
    add_action("shrug", "shrug");
    add_action("sigh", "sigh");
    add_action("sing", "sing");
    add_action("slap", "slap");
    add_action("slobber", "slobber");
    add_action("smirk", "smirk");
    add_action("smile", "smile");
    add_action("smooch", "smooch");
    add_action("snap", "snap");
    add_action("sneeze", "sneeze");
    add_action("snicker", "snicker");
    add_action("sniff", "sniff");
    add_action("snore", "snore");
    add_action("snuggle", "snuggle");
    add_action("spit", "spit");
    add_action("squeeze", "squeeze");
    add_action("stare", "stare");
    add_action("strip", "strip");
    add_action("strut", "strut");
    add_action("sulk", "sulk");
    add_action("taunt", "taunt");
    add_action("thank", "thank");
    add_action("think", "think");
    add_action("tickle", "tickle");
    add_action("tremble", "tremble");
    add_action("tsk", "tsk");
    add_action("twiddle", "twiddle");
    add_action("wait", "wait");
    add_action("wake", "wake");
    add_action("wave", "wave");
    add_action("whine", "whine");
    add_action("whistle", "whistle");
    add_action("wiggle", "wiggle");
    add_action("worship", "worship");
    add_action("wink", "wink");
    add_action("yawn", "yawn");
    add_action("yodel", "yodel");
}

get_adverb(str) {
    if (str == "angrily") { return str; }
    if (str == "arrogantly") { return str; }
    if (str == "awfully") { return str; }
    if (str == "audibly") { return str; }
    if (str == "badly") { return str; }
    if (str == "beautifully") { return str; }
    if (str == "boredly") { return str; }
    if (str == "boldly") { return str; }
    if (str == "brilliantly") { return str; }
    if (str == "briefly") { return str; }
    if (str == "bluntly") { return str; }
    if (str == "bitterly") { return str; }
    if (str == "calmly") { return str; }
    if (str == "cheerfully") { return str; }    
    if (str == "coldly") { return str; }
    if (str == "clearly") { return str; }
    if (str == "closely") { return str; }
    if (str == "comically") { return str; }
    if (str == "cruelly") { return str; }
    if (str == "cutely") { return str; }
    if (str == "decently") { return str; }
    if (str == "deeply") { return str; }
    if (str == "determinedly") { return str; }
    if (str == "diabolically") { return str; }
    if (str == "demonically") { return str; }
    if (str == "dirtily") { return str; }
    if (str == "dignifiedly") { return str; }
    if (str == "disgustingly") { return str; }
    if (str == "drily") { return str; }
    if (str == "dizzily") { return str; }
    if (str == "eerily") { return str; }
    if (str == "elegantly") { return str; }
    if (str == "enthousiastically") { return str; }
    if (str == "endlessly") { return str; }
    if (str == "erotically") { return str; }
    if (str == "evilly") { return str; }
    if (str == "fabulously") { return str; }
    if (str == "flegmatically") { return str; }
    if (str == "fearlessly") { return str; }
    if (str == "fearfully") { return str; }
    if (str == "firmly") { return str; }
    if (str == "fiercefully") { return str; }
    if (str == "frankly") { return str; }
    if (str == "funnily") { return str; }
    if (str == "frenetically") { return str; }
    if (str == "gently") { return str; }
    if (str == "girlishly") { return str; }
    if (str == "gleefully") { return str; }
    if (str == "happily") { return str; }
    if (str == "heartily") { return str; }
    if (str == "heinously") { return str; }
    if (str == "hellishly") { return str; }
    if (str == "helplessly") { return str; }
    if (str == "hilariously") { return str; }
    if (str == "humbly") { return str; }
    if (str == "hungrily") { return str; }
    if (str == "horribly") { return str; }
    if (str == "hornily") { return str; }
    if (str == "idlercilessly") { return str; }
    if (str == "mildly") { return str; }
    if (str == "mimically") { return str; }
    if (str == "merrily") { return str; }
    if (str == "menacingly") { return str; }
    if (str == "mightily") { return str; }
    if (str == "malevolently") { return str; }
    if (str == "meekly") { return str; }
    if (str == "miserably") { return str; }
    if (str == "mischievously") { return str; }
    if (str == "mockingly") { return str; }
    if (str == "mournfully") { return str; }
    if (str == "monstrously") { return str; }
    if (str == "musically") { return str; }
    if (str == "nicely") { return str; }
    if (str == "neatly") { return str; }
    if (str == "nonchalantly") { return str; }
    if (str == "obscurely") { return str; }
    if (str == "oddly") { return str; }
    if (str == "painfully") { return str; }
    if (str == "powerfully") { return str; }
    if (str == "pitifully") { return str; }
    if (str == "openly") { return str; }
    if (str == "promptly") { return str; }
    if (str == "patiently") { return str; }
    if (str == "pervertedly") { return str; }
    if (str == "philantropically") { return str; }
    if (str == "politely") { return str; }
    if (str == "philosophically") { return str; }
    if (str == "poetically") { return str; }
    if (str == "proudly") { return str; }
    if (str == "protectively") { return str; }
    if (str == "quizzically") { return str; }
    if (str == "quickly") { return str; }
    if (str == "repeatedly") { return str; }
    if (str == "rhetorically") { return str; }
    if (str == "remorsefully") { return str; }
    if (str == "sadly") { return str; }
    if (str == "scornfully") { return str; }
    if (str == "sarcastically") { return str; }
    if (str == "slowly") { return str; }
    if (str == "strangely") { return str; }
    if (str == "sheepishly") { return str; }
    if (str == "sensually") { return str; }
    if (str == "sexily") { return str; }
    if (str == "satanically") { return str; }
    if (str == "sceptically") { return str; }
    if (str == "shrilly") { return str; }
    if (str == "silently") { return str; }
    if (str == "sternly") { return str; }
    if (str == "skillfully") { return str; }
    if (str == "sinfully") { return str; }
    if (str == "subconsciously") { return str; }
    if (str == "subtly") { return str; }
    if (str == "tunefully") { return str; }
    if (str == "toothlessly") { return str; }
    if (str == "thoughtfully") { return str; }
    if (str == "vengefully") { return str; }
    if (str == "utterly") { return str; }
    if (str == "wholeheartedly") { return str; }
    if (str == "wrongfully") { return str; }
    if (str == "wetly") { return str; }
    if (str == "wickedly") { return str; }
    if (str == "wimpily") { return str; }
    if (str == "wondrously") { return str; }
    if (str == "wryly") { return str; }
    if (str == "wrathfully") { return str; }
    if (str == "xenophobically") { return str; }
    if (str == "zealously") { return str; }
    if (str == "zen-likely") { return str; }
    if (str == "zymotically") { return str; }
}

get_bodypart(str) {
    if (str == "head") { return str; }
    if (str == "stomach") { return str; }
    if (str == "back") { return str; }
    if (str == "cheek") { return str; }
    if (str == "neck") { return str; }
    if (str == "hand") { return str; }
    if (str == "butt") { return str; }
    if (str == "buttocks") { return str; }
    if (str == "foot") { return str; }
    if (str == "shoulder") { return str; }
    if (str == "toes") { return str; }
    if (str == "fingers") { return str; }
}

emotes() {
    if (ghost())
        return 0;
        write("To list the available emotes type 'help emotes'.\n");
        return 1;
} 

adverbs() {
    if (ghost())
        return 0;
    write("To list the available adverbs and bodyparts type 'help adverbs'.\n");
    return 1;
}

ack(str) {
    if (ghost())
        return 0;
    adverb = get_adverb(str);
    if (!adverb) { adverb = "thoughtfully"; }
    write("You ack " + adverb + ".\n");
    say(cap_name + " acks " + adverb + ".\n");
    return 1;
}

agree(str) {
    object who;
    if (ghost())
        return 0;
    if (!str) {
        write("You totally agree.\n");
        say(cap_name + " totally agrees.\n");
        return 1;
    }
    who = present(lower_case(str), environment(this_player()));
    if (!who || !living(who) || who == this_player())
        return 0;
    tell_object(who, cap_name + " totally agrees with you.\n");
    write("You totally agree with " + capitalize(str) +".\n");
    say(cap_name + " agrees with " + capitalize(str) + ".\n", who);
    return 1;
}


ah(str) {
    if (ghost())
        return 0;
    adverb = get_adverb(str);
    if (!adverb) { adverb = "thoughtfully"; }
    write("You go 'Ah' " + adverb + ".\n");
    say(cap_name + " goes 'Ah' " + adverb + ".\n");
    return 1;
}

apologize(str) {
    object who;
    if (ghost())
        return 0;
    if (!str) {
        write("You apologize humbly.\n");
        say(cap_name + " apologizes.\n");
        return 1;
    }
    who = present(lower_case(str), environment(this_player()));
    if (!who || !living(who) || who == this_player())
        return 0;
    tell_object(who, cap_name + " apologizes to you.\n");
    write("You apologize to " + capitalize(str) +".\n");
    say(cap_name + " apologizes to " + capitalize(str) + ".\n", who);
    return 1;
}

applaud(str) {
    if (ghost())
        return 0;
    adverb = get_adverb(str);
    if (!adverb) { adverb = "wholeheartedly"; }
    write("You applaud " + adverb + ".\n");
    say(cap_name + " applauds " + adverb + ".\n");
    return 1;
}

argh(str) {
    if (ghost())
        return 0;
    adverb = get_adverb(str);
    if (!adverb) { adverb = "monstrously"; }
    write("You scream 'AARGH' " + adverb + ".\n");
    say(cap_name + " screams 'AARGH' " + adverb + ".\n");
    return 1;
}

bark(str) {
    object who;
    if (ghost())
        return 0;
    if (!str) {
        write("You start barking like a dog.\n");
        say(cap_name+" starts barking like a dog.\n");
        return 1;
    }
    who = present(lower_case(str), environment(this_player()));
    if (!who || !living(who) || who == this_player())
        return 0;
    tell_object(who, cap_name + " barks at you.\n");
    write("You bark at " + capitalize(str) +".\n");
    say(cap_name + " barks at " + capitalize(str) + ".\n", who);
    return 1;
}

beg(str) {
    object who;
    if (ghost())
        return 0;
    if (!str) {
        write("You beg pitifully.\n");
        say(cap_name+" pitifully begs.\n");
        return 1;
    }
    who = present(lower_case(str), environment(this_player()));
    if (!who || !living(who) || who == this_player())
        return 0;
    tell_object(who, cap_name + " pitifully begs you.\n");
    write("You pitifully beg " + capitalize(str) +".\n");
    say(cap_name + " pitifully begs " + capitalize(str) + ".\n", who);
    return 1;
}

bleed(str) {
    if (ghost())
        return 0;
    adverb = get_adverb(str);
    if (!adverb) { adverb = "relentlessly"; }
    write("You bleed " + adverb + ".\n");
    say(cap_name + " bleeds " + adverb + ".\n");
    return 1;
}

blink(str) {
    object who;
    if (ghost())
        return 0;
    if (!str) {
        write("You blink.\n");
        say(cap_name + " blinks.\n");
        return 1;
    }
    who = present(lower_case(str), environment(this_player()));
    if (!who || !living(who) || who == this_player())
        return 0;
    tell_object(who, cap_name + " blinks at you.\n");
    write("You blink at " + capitalize(str) +".\n");
    say(cap_name + " blinks at " + capitalize(str) + ".\n", who);
    return 1;
}

blush(str) {
    if (ghost())
        return 0;
    write("You blush to a deep crimson.\n");
    say(cap_name + " blushes and turns away shyly.\n");
    return 1;
}

boo(str) {
    object who;
    if (ghost())
        return 0;
  l_object(who, cap_name + " boos at you insolently.\n");
    write("You boo at " + capitalize(str) +" insolently.\n");
    say(cap_name + " boos at " + capitalize(str) + " insolently.\n", who);
    return 1;
}

bore(str) {
    object who;= this_player())
        return 0;
    tell_object(who, cap_name + " bores you to death.\n");
    write("You bore " + capitalize(str) +" to death.\n");
    say(cap_name + " bores " + capitalize(str) + " to death.\n", who);
    return 1;
}

bored() {
    if (ghost())
        return 0;
    write("You're bored.\n");
    say(cap_name + " is bored.\n");
    return 1;
}

bounce(str) {
    if (ghost())
        return 0;
    adverb = get_adverb(str);
    if (!adverb) { adverb = "skillfully"; }
    write("You bounce around " + adverb + ".\n");
    say(cap_name + " bounce " + adverb + ".\n");
    return 1;
}

bow(str) {
    object who;
    if (ghost())
        return 0;
    if (!str) {
        write("You bow to your audience.\n");
        say(cap_name + " bows gracefully.\n");
        return 1;
    }
    who = present(lower_case(str), environment(this_player()));
    if (!who || !living(who) || who == this_player())
        return 0;
    tell_object(who, cap_name + " bows before you.\n");
    write("You bow to " + capitalize(str) +".\n");
    say(cap_name + " bows to " + capitalize(str) + ".\n", who);
    return 1;
}

burp(str) {
    if (ghost())
        return 0;
    adverb = get_adverb(str);
    if (!adverb) { adverb = "rudely"; }
    write("You burp " + adverb + ".\n");
    say(cap_name + " burps " + adverb + ".\n");
    return 1;
}

cackle(str) {
    if (ghost())
        return 0;
    adverb = get_adverb(str);
    if (!adverb) { adverb = "gleefully"; }
    write("You cackle " + adverb + ".\n");
    say(cap_name + " throws " + the_owner->query_possessive() +
        " head back and cackles " + adverb + "!\n");
    return 1;
}

calculate() {
    if (ghost())
   	return 0;
    write("You start calculating pi's decimals...\n");
    say(cap_name + " started calculating pi's decimals once again.\n");
    return 1;
}
   
   
   
caress(str) {
    object who;
    string target;
    if (ghost())
        return 0;
    if (str == 0)
        return 0;
    target = str;
    if (sscanf(str, "%s in the %s", target, bodypart)) {
        get_bodypart(bodypart); 
    }
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player())
        return 0;
    if (!bodypart) {
        tell_object(who, cap_name + " caresses you.\n");
        say(cap_name + " caresses " + capitalize(target) + ".\n", who);
        write("You caress " + capitalize(target) + ".\n");
    }
    else {
        tell_object(who, cap_name + " caresses your " + bodypart +
                "\n");
        say(cap_name + " caresses " + capitalize(target) + "'s " +
                bodypart + ".\n", who);
        write("You caress " + capitalize(target) + "'s " +
                bodypart + ".\n");
    }
    return 1;
}

cheer(str) {
    if (ghost())
        return 0;
    adverb = get_adverb(str);
    if (!adverb) { adverb = "enthousiastically"; }
    write("You cheer " + adverb + ".\n");
    say(cap_name + " cheers " + adverb + ".\n");
    return 1;
}

chuckle(str) {
    if (ghost())
        return 0;
    adverb = get_adverb(str);
    if (!adverb) { adverb = "heartily"; }
    write("You chuckle " + adverb + ".\n");
    say(cap_name + " chuckles " + adverb + ".\n");
    return 1;
}

clap(str) {
    if (ghost())
        return 0;
    adverb = get_adverb(str);
    if (!adverb) { adverb = "briefly"; }
    write("You clap " + adverb + ".\n");
    say(cap_name + " claps " + adverb + ".\n");
    return 1;
}

click() {
    if (ghost())
        return 0;
    write("You start make clicking sound with your tongue.\n");
    say(cap_name + " starts making some weird clicking sounds with his tongue.\n");
    return 1;
}

comfort(str) {
    object who;
    if (ghost())
        return 0;
    if (!str)
        return 0;
    who = present(lower_case(str), environment(this_player()));
    if (!who || !living(who) || who == this_player())
        return 0;
    tell_object(who, cap_name + " comforts you.\n");
    write("You comfort " + capitalize(str) + ".\n");
    say(cap_name + " comforts " + capitalize(str) + ".\n", who);
    return 1;
}

confuse(str) {
    object who;
    if (ghost())
        return 0;
    if (!str)
        return 0;
    who = present(lower_case(str), environment(this_player()));
    if (!who || !living(who) || who == this_player())
        return 0;
    tell_object(who, cap_name + " comforts you.\n");
    write("You utterly confuse " + capitalize(str) + ".\n");
    say(cap_name + " confuses " + capitalize(str) + " completely.\n", who);
    return 1;
}

confused() {
    if (ghost())
        return 0;
    write("You are confused.\n");
    say(cap_name + " seems confused.\n");
    return 1;
}

congratulate(str) {
    object who;
    if (ghost())
        return 0;
    if (!str)
        return 0;
    who = present(lower_case(str), environment(this_player()));
    if (!who || !living(who) || who == this_player())
        return 0;
    tell_object(who, cap_name + " congratulates you.\n");
    write("You congratulate " + capitalize(str) + ".\n");
    say(cap_name + " congratulates " + capitalize(str) + ".\n", who);
    return 1;
}

cough(str) {
    if (ghost())
        return 0;
    adverb = get_adverb(str);
    if (!adverb) { adverb = "noisily"; }
    write("You cough " + adverb + ".\n");
    say(cap_name + " coughs " + adverb + ".\n");
    return 1;
}

croak() {
    if (ghost())
        return 0;
    write("You croak like a frog.\n");
    say(cap_name + " croaks like a frog.\n");
    return 1;
}

cry() {
    if (ghost())
        return 0;
    write("Tears fill your eyes and flow down in rivers.\n");
    say(cap_name + " bursts into tears.\n");
    return 1;
}

cuddle(str) {
    object who;
    if (ghost())
        return 0;
    if (!str)
        return 0;
    who = present(lower_case(str), environment(this_player()));
    if (!who || !living(who) || who == this_player())
        return 0;
    tell_object(who, cap_name + " cuddles you.\n");
    write("You cuddle " + capitalize(str) + ".\n");
    say(cap_name + " cuddles " + capitalize(str) + ".\n", who);
    return 1;
}

curse() {
    if (ghost())
        return 0;
    write("You curse angrily.\n");
    say(cap_name + " curses angrily.\n");
    return 1;
}

curtsey(str) {
    if (ghost())
        return 0;
    adverb = get_adverb(str);
    if (!adverb) { adverb = "gracefully"; }
    write("You curtsey " + adverb + ".\n");
    say(cap_name + " curtseys " + adverb + ".\n");
    return 1;
}

dance(str) {
    object who;
    if (ghost())
        return 0;
    if (!str) {
        write("Feels silly, doesn't it?\n");
        say(cap_name + " does the disco duck.\n");
        return 1;
    }
    who = present(lower_case(str), environment(this_player()));
    if (!who || !living(who) || who == this_player())
        return 0;
    tell_object(who, cap_name + " sweeps you across the dance floor.\n");
    write("You sweep " + capitalize(str) +" across the dance floor.\n");
    say(cap_name + " sweeps " + capitalize(str) + " across the dance floor.\n", who);
    return 1;
}

disagree(str) {
    object who;
    if (ghost())
        return 0;
    if (!str) {
        write("You steeply disagree.\n");
        say(cap_name + " disagrees steeply.\n");
        return 1;
    }
    who = present(lower_case(str), environment(this_player()));
    if (!who || !living(who) || who == this_player())
        return 0;
    tell_object(who, cap_name + " steeply disagrees your opinion.\n");
    write("You steeply disagree " + capitalize(str) +"'s opinion.\n");
    say(cap_name + " steeply disagrees " + capitalize(str) + "'s opinion.\n", who);
    return 1;
}

dream() {
    if (ghost())
        return 0;
    write("You dream about hot, sunny beach with lo;
        return 1;
    }
    who = present(lower_case(str), environment(this_player()));
    if (!who || !living(who) || who == this_player())
        return 0;
    tell_object(who, cap_name + " drools all over you.\n");
    write("You drool all over " + capitalize(str) +".\n");
    say(cap_name + " drools all over " + capitalize(str) + ".\n", who);
    return 1;
}

eep(string str) {
    object wh;
    if (ghost())
        return 0;
    if (!str) {
        write("You eep fearfully.\n");
      h);
    write("You eep at " + capitalize(str) + " fearfully.\n");
    return 1;
}

eww(string str) {
    object wh;
    if (ghost())
        return 0;
    if (!str) {
        write("You go 'Eww' in disgust.\n");
        say(cap_name+" go 'Eww' in disgust.\n");
        return 1;
    }
    wh = present(str, environment(this_player()));
    if (!wh || !living(wh) || wh == this_player())
        return 0;
    tell_object(wh, cap_name + " goes 'Eww' at you.\n");
    say(cap_name + " goes 'Eew' at " + capitalize(str) + " in disgust.\n", wh);
    write("You eww at " + capitalize(str) + ".\n");
    return 1;
}

excuse(str) {
    object who;
    if (ghost())
        return 0;
    if (!str)
        return 0;
    who = present(lower_case(str), environment(this_player()));
    if (!who || !living(who) || who == this_player())
        return 0;
    tell_object(who, cap_name + " excuses you.\n");
    write("You excuse " + capitalize(str) + ".\n");
    say(cap_name + " excuses " + capitalize(str) + ".\n", who);
    return 1;
}


fart() {
    if (ghost())
        return 0;
    write("How rude!\n");
    say(cap_name + " lets off a real rip-roarer.\n");
    return 1;
}

fear() {
    if (ghost())
        return 0;
    write("You hop in the air and start shiver in fear.\n");
    say(cap_name + " hops in the air and starts to shiver in fear.\n");
    return 1;
}

flex() {
    if (ghost())
        return 0;
    write("You flex your tyrannous muscles.\n");
    say(cap_name + " flexes his tyrannous muscles.\n");
    return 1;
}

flip() {
    if (ghost())
        return 0;
    write("You flip head over heels.\n");
    say(cap_name + " flips head over heels.\n");
    return 1;
}

flirt(str) {
    object who;
    if (ghost())
        return 0;
    if (!str)
        return 0;
    who = present(lower_case(str), environment(this_player()));
    if (!who || !living(who) || who == this_player())
        return 0;
    tell_object(who, cap_name + " flirts with you.\n");
    write("You flirt with " + capitalize(str) + ".\n");
    say(cap_name + " flirts with " + capitalize(str) + ".\n", who);
    return 1;
}

fondle(str) {
    object who;
    if (ghost())
        return 0;
    if (!str)
        return 0;
    who = present(lower_case(str), environment(this_player()));
    if (!who || !living(who) || who == this_player())
        return 0;
    tell_object(who, cap_name + " fondles you.\n");
    write("You fondle " + capitalize(str) + ".\n");
    say(cap_name + " fondles " + capitalize(str) + ".\n", who);
    return 1;
}

foretell() {
    if (ghost())
    	return 0;
    write("You try to foretell the future... but fail.\n");
    say(cap_name + " tries to foretell the future... but fails.\n");
    return 1;
}

freeze() {
    if (ghost())
    	return 0;
    write("You freeze on your position don't move even a millimeter.\n");
    say(cap_name + " freezes on one place without moving even a millimeter.\n");
    return 1;
}

french(str) {
    object who;
    if (ghost())
        return 0;
    if (!str)
        return 0;
    who = present(lower_case(str), environment(this_player()));
    if (!who || !living(who) || who == this_player())
        return 0;
    tell_object(who, cap_name +
       " gives you a deep and passionate kiss..it seems to take forever...\n");
    write("You give " + capitalize(str) + " a REAL kiss..it lasts a long time...\n");
    say(cap_name + " gives " + capitalize(str) +
       " a deep and passionate kiss..it seems to take forever...\n", who);
    return 1;
}

frown(str) {
    if (ghost())
        return 0;
    adverb = get_adverb(str);
    if (!adverb) { adverb = "sceptically"; }
    write("You frown " + adverb + ".\n");
    say(cap_name + " frowns " + adverb + ".\n");
    return 1;
}

gasp() {
    if (ghost())
        return 0;
    write("You gasp in astonishment.\n");
    say(cap_name + " gasps in astonishment!\n");
    return 1;
}

giggle(str) {
    if (ghost())
        return 0;
    adverb = get_adverb(str);
    if (!adverb) { adverb = "inanely"; }
    write("You giggle " + adverb + ".\n");
    say(cap_name + " giggle " + adverb + ".\n");
    return 1;
}

gigglesnort() {
    if (ghost())
        return 0;
    write("You gigglesnort loudly.\n");
    say(cap_name + "'s wild giggle is occasionally interrupted by loud snorts.\n");
    return 1;
}

glare(str) {
    object who;
    if (ghost())
        return 0;
    if (!str)
        return 0;
    who = present(lower_case(str), environment(this_player()));
    if (!who || !living(who) || who == this_player())
        return 0;
    tell_object(who, cap_name + " glares at you.\n");
    write("You glare stonily at " + capitalize(str) + ".\n");
    say(cap_name + " glares at " + capitalize(str) + ".\n", who);
    return 1;
}

glug() {
    if (ghost())
        return 0;
    write("You make out some weird sounds with you tongue and throat.\n");
    say(cap_name + "makes out some weird sounds with his tongue and throat.\n");
    return 1;
}

greet(str) {
    object who;
    if (ghost())
        return 0;
    if (!str) {
        write("You greet everyone.\n");
        say(cap_name + " greets everyone.\n");
        return 1;
    }
    who = present(lower_case(str), environment(this_player()));
    if (!who || !living(who) || who == this_player())
        return 0;
    tell_object(who, cap_name + " greets you.\n");
    write("You greet " + capitalize(str) +".\n");
    say(cap_name + " greets " + capitalize(str) + ".\n", who);
    return 1;
}


grin(str) {
    if (ghost())
        return 0;
    adverb = get_adverb(str);
    if (!adverb) { adverb = "evilly"; }
    write("You grin " + adverb + ".\n");
    say(cap_name + " grins " + adverb + ".\n");
    return 1;
}

groan(str) {
    if (ghost())
        return 0;
    adverb = get_adverb(str);
    if (!adverb) { adverb = "loudly"; }
    write("You groan " + adverb + ".\n");
    say(cap_name + " groans " + adverb + ".\n");
    return 1;
}

grope(str) {
    object who;
    if (ghost())
        return 0;
    if (!str)
        return 0;
    who = present(lower_case(str), environment(this_player()));
    if (!who || !living(who) || who == this_player())
        return 0;
    tell_object(who, cap_name + " gropes you.\n");
    write("SlapSlap!\n");
    say(cap_name + " gropes " + capitalize(str) + ".\n", who);
    return 1;
}

growl(str) {
    object who;
    if (ghost())
        return 0;
    if (!str) {
        write("You growl.\n");
        say(cap_name + " growls.\n");
        return 1;
    }
    who = present(lower_case(str), environment(this_player()));
    if (!who || !living(who) || who == this_player())
        return 0;
    tell_object(who, cap_name + " growls at you.\n");
    write("You growl at " + capitalize(str) +".\n");
    say(cap_name + " growls at " + capitalize(str) + ".\n", who);
    return 1;
}

grr(str) {
    if (ghost())
    	return 0;
    adverb = get_adverb(str);
    if (!adverb) { adverb = "angrily"; }
    write("You go 'GRR' " + adverb + ".\n");
    say(cap_name + " goes 'GRRR' " + adverb + ".\n");
    return 1;
}

gurgle(str) {
    if (ghost())
        return 0;
    adverb = get_adverb(str);
    if (!adverb) { adverb = "toothlessly"; }
    write("You gurgle " + adverb + ".\n");
    say(cap_name + " gurgles " + adverb + ".\n");
    return 1;
}

hail(string str) {
    object wh;
    if (ghost())
        return 0;
    if (!str) {
        write("You hail ev  write("You hail " + capitalize(str) + ".\n");
    return 1;
}

heh() {
    if (ghost())
        return 0;
    write("You go 'Heh'.\n");
    say(cap_name + " goes 'Heh'.\n");
    return 1;
}

hiccup() {
    if (ghost())
        return 0;
    write("Hic!\n");
    say(cap_name + " hiccups.\n");
    return 1;
}

hmm(str) {
    if (ghost())
        return 0;
    adverb = get_adverb(str);
    if (!adverb) { adverb = "thoughtfully"; }
    write("You hmm " + adverb + ".\n");
    say(cap_name + " hmms " + adverb + ".\n");
    return 1;
}

hmpf(string str) {
    object wh;
    if (ghost())
        return 0;
    if (!str) {
        write("You hmpf.\n");
        say(cap_name+" goes hmpf.\n");
        return 1;
    }
    wh = present(str, environment(this_player()));
    if (!wh || !living(wh) || wh == this_plau Hmph indifferently.\n");
        say(cap_name + " Hmphs indifferently.\n");
        return 1;
    }
    wh = present(str, environment(this_player()));
    if (!wh || !living(wh) || wh == this_player())
        return 0;
    tell_object(wh, cap_name + " Hmphs at you.\n");
    say(cap_name + " Hmphs at " + capitalize(str) + ".\n", wh);
    write("You Hmph at " + capitalize(str) + ".\n");
    return 1;
}

hooray() {
    if (ghost())
    	return 0;
    write("You clap your hands and yell: HOORAY!\n");
    say(cap_name + " starts clapping his hands and yelling: HOORAY!\n");
    return 1;
}

hug(str) {
    object who;
    if (ghost())
        return 0;
    if (str == 0)
        return 0;
    who = present(lower_case(str), environment(this_player()));
    if (!who || !living(who) || who == this_player())
        return 0;
    tell_object(who, cap_name + " hugs you.\n");
    write("You hug " + capitalize(str) + ".\n");
    say(cap_name + " hugs " + capitalize(str) + ".\n", who);
    return 1;
}

hum() {
    if (ghost())
    	return 0;
    write("You start humming somehow familiar tune.\n");
    say(cap_name + " starts humming somehow familiar tune.\n");
    return 1;
}

kick(str) {
    object who;
    string target;
    if (ghost())
        return 0;
    if (str == 0)
        return 0;
    target = str;
    if (sscanf(str, "%s in the %s", target, bodypart)) {
        get_bodypart(bodypart); 
    }
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player())
        return 0;
    if (!bodypart) {
        tell_object(who, cap_name + " kicks you.   OUCH!!\n");
        say(cap_name + " kicks " + capitalize(target) + ".\n", who);
        write("You kick " + capitalize(target) + ".\n");
    }
    else {
        tell_object(who, cap_name + " kicks you in the " + bodypart +
                ".   OUCH!!\n");
        say(cap_name + " kicks " + capitalize(target) + " in the " +
                bodypart + ".\n", who);
        write("You kick " + capitalize(target) + " in the " +
                bodypart + ".\n");
    }
    return 1;
}

kiss(str) {
    object who;
    if (ghost())
        return 0;
    if (str == 0)
        return 0;
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
        return 0;
    tell_object(who, cap_name + " kisses you.\n");
    say(cap_name + " kisses " + capitalize(str) + ".\n", who);
    if (call_other(who, "query_frog")) {
        call_other(this_player(), "frog_curse", 1);
        call_other(who, "frog_curse", 0);
        return 1;
    }
    write("You kiss " + capitalize(str) + ".\n");
    return 1;
}

knee(str) {
    object who;
    if (ghost())
        return 0;
    if (str == 0)
        return 0;
    who = present(lower_case(str), environment(this_player()));
    if (!who || !living(who) || who == this_player())
        return 0;
    if (who->query_male()) {
        tell_object(who, cap_name + " hits you with " +
                    the_owner->query_possessive() + " knee below your belt!\n" +
                    "You double over and fall to the ground, writhing in " +
                    "excrutiating pain,\nfeeling like you may throw up " +
                    "everything you have eaten!\n");
        say(cap_name + " suddenly raises " + the_owner->query_possessive() +
            " knee, sending " + capitalize(str) + " to the floor, writhing in pain!\n",
            who);
        write("You hit " + capitalize(str) + " with your knee.\n");
    }
    else {
        tell_object(who, cap_name + " tries to knee you, without much effect.\n");
        say(cap_name + " tries to knee " + capitalize(str) + ", without much effect.\n", who);
        write("You try to knee " + capitalize(str) + ". Not very effective though.\n");
    }
    return 1;
}

laugh() {
    if (ghost())
        return 0;
    write("You fall down laughing.\n");
    say(cap_name + " falls down laughing.\n");
    return 1;
}

lick(str) {
    object who;
    if (ghost())
        return 0;
    if (str == 0)
        return 0;
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
        return 0;
    tell_object(who, cap_name + " licks you.\n");
    say(cap_name + " licks " + capitalize(str) + ".\n", who);
    write("You lick " + capitalize(str) + ".\n");
    return 1;
}

love(str) {
    object who;
    if (ghost())
        return 0;
    if (str == 0)
        return 0;
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
        return 0;
    tell_object(who, cap_name + " whispers to you sweet words of love.\n");
    say(cap_name + " whispers softly to " + capitalize(str) + ".\n", who);
    write("You tell your true feelings to " + capitalize(str) + ".\n");
    return 1;
}

lust(str) {
    object who;
    if (ghost())
        return 0;
    if (str == 0)
        return 0;
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
        return 0;
    tell_object(who, cap_name + " looks at you with THAT look in the eyes.\n");
    say(cap_name + " is filled with lust for " + capitalize(str) + ".\n", who);
    write("You are filled with lust for " + capitalize(str) + ".\n");
    return 1;
}

mercy(str) {
    object who;
    if (ghost())
        return 0;
    if (!str) {
        write("You beg for mercy.\n");
        say(cap_name+" begs for mercy.\n");
        return 1;
    }
    who = present(lower_case(str), environment(this_player()));
    if (!who || !living(who) || who == this_player())
        return 0;
    tell_object(who, cap_name + " pitifully begs you for mercy.\n");
    write("You pitifully beg " + capitalize(str) +" for mercy.\n");
    say(cap_name + " pitifully begs " + capitalize(str) + " for mercy.\n", who);
    return 1;
}


moan() {
    if (ghost())
        return 0;
    write("You start to moan.\n");
    say(cap_name + " starts moaning.\n");
    return 1;
}

mourn() {
    if (ghost())
        return 0;
    write("You mourn.\n");
    say(cap_name + " mourns for something.\n");
    return 1;
}

muah(string str) {
    object wh;
    if (ghost())
        return 0;
    if (!str) {
        write("You muah.\n");
        say(cap_name+" muahs.\n");
        return 1;
    }
    wh = present(str, environment(this_player()));
    if (!wh || !living(wh) || wh == this_player())
        return 0;
    tell_object(wh, cap_name + " muahs at you.\n");
    say(cap_name + " muahs at " + capitalize(str) + ".\n", wh);
    write("You muah at " + capitalize(str) + ".\n");
    return 1;
}

mrh(str) {
    if (ghost())
        return 0;
    adverb = get_adverb(str);
    if (!adverb) { adverb = "angrily"; }
    write("You go 'Mrh' " + adverb + ".\n");
    say(cap_name + " goes 'Mrh' " + adverb + ".\n");
    return 1;
}

nibble(str) {
    object who;
    if (ghost())
        return 0;
    if (str == 0)
        return 0;
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == th solemnly.\n");
    say(cap_name + " nods solemnly.\n");
    return 1;
}

nodnod() {
    if (ghost())
        return 0;
    write("You nod twice rapidly.\n");
    say(cap_name + " nods twice rapidly.\n");
    return 1;
}

observe(string str) {
    object wh;
    if (ghost())
        return 0;
    if (!str) {
    write("You look alertly to your left and right.\n");
    say(cap_name + " starts alertly observe everything around him.\n");
    return 1;
}
    wh = present(str, environment(this_player()));
    if (!wh || !living(wh) || wh == this_player())
        return 0;
    tell_object(wh, cap_name + " starts closely observe your every move.\n");
    say(cap_name + " starts closely observe " + capitalize(str) + "'s every move.\n", wh);
    write("You start closely observe " + capitalize(str) + "'s every move.\n");
    return 1;
}


ooo(string str) {
    object wh;
    if (ghost())
        return 0;
    if (!str) {
        write("You go 'Ooo' in wonder.\n");
        say(cap_name + " goes 'Ooo' in wonder.\n");
        return 1;
    }
    wh = present(str, environment(this_player()));
    if (!wh || !living(wh) || wh == this_pla  return 0;
    write("You utter 'Oops' and blush.\n");
    say(cap_name + " utters 'Oops' and blushes.\n");
    return 1;
}

pat(str) {
    object who;
    if (ghost())
        return 0;
    if (str == 0)
        return 0;
    who = present(lower_case(str), environment(this_player()));
    if (!who || !living(who) || who == this_player())
        return 0;
    tell_object(who, cap_name + " pats you on the head.\n");
    say(cap_name + " pats " + capitalize(str) + " on the head.\n", who);
    write("You pat " + capitalize(str) + " on the head.\n");
    return 1;
}

play() {
    if (ghost())
        return 0;
    write("You start playing pocket-billiard.\n");
    say(cap_name + " starts playing pocket-billiard for a change..\n");
    return 1;
}

poke(str) {
    object who;
    if (ghost())
        return 0;
    if (str == 0)
        return 0;
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
        return 0;
    tell_object(who, cap_name + " pokes you in the ribs.\n");
    say(cap_name + " pokes " + capitalize(str) + " in the ribs.\n", who);
    write("You poke " + capitalize(str) + " in the ribs.\n");
    return 1;
}

pout() {
    if (ghost())
        return 0;
    write("Ah, don't take it so hard.\n");
    say(cap_name + " pouts.\n");
    return 1;
}

puke(str) {
    object who;
    if (ghost())
        return 0;
    if(!str) {
        write("You puke on your shoes.\n");
        say(cap_name + " doubles over and puke.\n");
        return 1;
    }
    who = present(lower_case(str), environment(this_player()));
    if (!who || !living(who) || who == this_player())
        return 0;
    tell_object(who, cap_name + " pukes all over you!\n");
    write("You puke on " + capitalize(str) +".\n");
    say(cap_name + " pukes on " + capitalize(str) + ".\n", who);
    return 1;
}

purr(str) {
    if (ghost())
        return 0;
    adverb = get_adverb(str);
    if (!adverb) { adverb = "contently"; }
    write("You purr " + adverb + ".\n");
    say(cap_name + " purr " + adverb + ".\n");
    return 1;
}

puuh(str) {
    if (ghost())
        return 0;
    write("You go 'Puuh' in frustration.\n");
    say(cap_name + " goes 'Puuh' in frustration.\n");
    return 1;
}

refuse(str) {
    object who;
    if (ghost())
        return 0;
    if (!str)
        return 0;
    who = present(lower_case(str), environment(this_player()));
    if (!who || !living(who) || who == this_player())
        return 0;
    tell_object(who, cap_name + " refuses your generous offer.\n");
    write("You refuse " + capitalize(str) + "'s offer.\n");
    say(cap_name + " refuses " + capitalize(str) + "'s generous offer.\n", who);
    return 1;
}

ruffle(str) {
    object who;
    if (ghost())
        return 0;
    if (!str)
        return 0;
    who = present(lower_case(str), environment(this_player()));
    if (!who || !living(who) || who == this_player())
        return 0;
    tell_object(who, cap_name + " ruffles your hair playfully.\n");
    write("You ruffle " + capitalize(str) + "'s hair playfully.\n");
    say(cap_name + " ruffles " + capitalize(str) + "'s hair playfully.\n", who);
    return 1;
}

scare(string str) {
    object who;
    if (ghost())
    	return 0;
    if (!str)
    	return 0;
    who = present(lower_case(str), environment(this_player()));
    if (!who || !living(who) || who == this_player())
        return 0;
    tell_object(who, cap_name + " put his cold hand on your neck and starts screaming in your ear SCARING HELL OUTTA YOU!!\n");
    write("You put your hand on " + capitalize(str) + "'s neck scaring him to death.\n");
    say(cap_name + " puts his hand on " + capitalize(str) + "'s neck scaring him to death.\n", who);
    return 1;
}

scratch(str) {
    object who;
    string target;
    if (ghost())
        return 0;
    if (str == 0) {
    say(cap_name + " scratches " + the_owner->query_possessive() +" armpits idly.\n");
    write("You scratch yourself idly.\n");
    return 1; 
    }
    target = str;
    if (sscanf(str, "%s in the %s", target, bodypart)) {
        get_bodypart(bodypart); 
    }
    who = present(target, environment(this_player()));
    if (!who || !living(who)) 
        return 0;
    if (who == this_player()) {
     if (!bodypart) {
     say(cap_name + " scratches " + the_owner->query_possessive() +" armpits idly.\n");
     write("You scratch yourself idly.\n");
     return 1; 
     }
        say(cap_name + " scratches " + the_owner->query_possessive() +" " + bodypart + ".\n", who);
        write("You scratch your " + bodypart + ".\n");
        return 1;
      }
    
    if (!bodypart) {
        tell_object(who, cap_name + " scratches you.\n");
        say(cap_name + " scratches " + capitalize(target) + ".\n", who);
        write("You scratch " + capitalize(target) + ".\n");
    }
    else {
        tell_object(who, cap_name + " scratches your " + bodypart +".\n");
        say(cap_name + " scratches " + capitalize(target) + "'s " + bodypart + ".\n", who);
        write("You scratch " + capitalize(target) + "'s " + bodypart + ".\n");
    }
    return 1;
}

scream() {
    if (ghost())
        return 0;
    write("ARRGGGGGGHHHHHH!!!!\n");
    say(cap_name + " screams loudly!\n");
    return 1;
}

shake(str) {
    object who;
    if (ghost())
        return 0;
    if(!str) {
        write("You're shaking in your boots.\n");
        say(cap_name + " shakes and quivers like a bowlful of jelly.\n");
        return 1;
    }
    who = present(lower_case(str), environment(this_player()));
    if (!who || !living(who) || who == this_player())
        return 0;
    tell_object(who, cap_name + " shakes your hand.\n");
    write("You shake hands with " + capitalize(str) +".\n");
    say(cap_name + " shakes " + capitalize(str) + "s hand.\n", who);
    return 1;
}

shiver() {
    if (ghost())
        return 0;
    write("Brrrrrr!!!\n");
    say(cap_name + " shivers from the cold.\n");
    return 1;
}

shrug(str) {
    if (ghost())
        return 0;
    adverb = get_adverb(str);
    if (!adverb) { adverb = "helplessly"; }
    write("You shrug " + adverb + ".\n");
    say(cap_name + " shrugs " + adverb + ".\n");
    return 1;
}

sigh(str) {
    if (ghost())
        return 0;
    adverb = get_adverb(str);
    if (!adverb) { adverb = "deeply"; }
    write("You sigh " + adverb + ".\n");
    say(cap_name + " sighs " + adverb + ".\n");
    return 1;
}

sing() {
    if (ghost())
        return 0;
    write("Oh sole mio!\n");
    say(cap_name + " sings in Italian.\n");
    return 1;
}

slap(str) {
    object who;
    if (ghost())
        return 0;
    if (str == 0)
        return 0;
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
        returntically"; }
    write("You slobber " + adverb + ".\n");
    say(cap_name + " slobbers " + adverb + ".\n");
    return 1;
}

smirk() {
    if (ghost())
        return 0;
    write("You smirk.\n");
    say(cap_name + " smirks.\n");
    return 1;
}

smile(str) {
    object who;
    if (ghost()) {
        write("You smile inwardly.\n");
        return 1;
    }
    if(!str) {
        write("You smile happily.\n");
        say(cap_name + " smiles happily.\n");
        return 1;
    }
    who = present(lower_case(str), environment(this_player()));
    if (!who || !living(who) || who == this_player())
        return 0;
    tell_object(who, cap_name + " smiles at you.\n");
    write("You smile at " + capitalize(str) +".\n");
    say(cap_name + " smiles at " + capitalize(str) + ".\n", who);
    return 1;
}

smooch(string str) {
    object wh;
    if (ghost())
        return 0;
    if (!str) {
        write("You desperately look for somebody to smooch.\n");
        say(cap_name+" desperately looks for somebody to smooch.\n");
        return 1;
    }
    wh = present(str, environment(this_player()));
    if (!wh || !living(wh) || wh == this_player())
        return 0;
    tell_object(wh, cap_name + " gives you a smooch.\n");
    say(cap_name + " gives " + capitalize(str) + " a quick smooch.\n", wh);
    write("You give " + capitalize(str) + " a quick smooch.\n");
    return 1;
}

snap() {
    if (ghost())
        ret(ghost())
        return 0;
    adverb = get_adverb(str);
    if (!adverb) { adverb = "wickedly"; }
    write("You snicker " + adverb + ".\n");
    say(cap_name + " snickers " + adverb + ".\n");
    return 1;
}

sniff() {
    if (ghost())
        return 0;
    write("You sniff.\n");
    say(cap_name + " sniffs.\n");
    return 1;
}

snore() {
    if (ghost())
        return 0;
    write("Zzzzzzzzzz...\n");
    say(cap_name + " snores loudly.\n");
    return 1;
}

snuggle(str) {
    object who;
    if (ghost())
        return 0;
    if (str == 0)
        return 0;
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
        return 0;
    write("You snuggle " + capitalize(str) + ".\n");
    say(cap_name + " snuggles up to " + capitalize(str) + ".\n", who);
    tell_object(who, cap_name + " snuggles up to you.\n");
    return 1;
}

spit(str) {
    object who;
    if (ghost())
        return 0;
    if(!str) {
        write("You spit.\n");
        say(cap_name + " spits on the ground.\n");
        return 1;
    }
    who = present(lower_case(str), environment(this_player()));
    if (!who || !living(who) || who == this_player())
        return 0;
    tell_object(who, cap_name + " spits on you!\n");
    write("You spit on " + capitalize(str) +".\n");
    say(cap_name + " spits on " + capitalize(str) + ".\n", who);
    return 1;
}

squeeze(str) {
    object who;
    if (ghost())
        return 0;
    if (str == 0)
        return 0;
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
        return 0;
    write("You squeeze " + capitalize(str) + " fondly.\n");
    say(cap_name + " squeezes " + capitalize(str) + " fondly.\n", who);
    tell_object(who, cap_name + " squeezes you fondly.\n");
    return 1;
}

stare(str) {
    object who;
    if (ghost())
        return 0;
    if(!str) {
        write("You stare into space.\n");
        say(cap_name + " stares into space.\n");
        return 1;
    }
    who = present(lower_case(str), environment(this_player()));
    if (!who || !living(who) || who == this_player())
        return 0;
    tell_object(who, cap_name + " stares deep into your eyes.\n");
    write("You stare dreamily at " + capitalize(str) +".\n");
    say(cap_name + " stares dreamily at " + capitalize(str) + ".\n", who);
    return 1;
}

strip() {
    if (ghost())
        return 0;
    write("You start dancing and STRIPPING off your clothes.\n");
    say(cap_name + " starts dancing and STRIPPING off his clothes, YUCK!\n");
    return 1;
}

strut() {
    if (ghost())
        return 0;
    write("Strut your stuff!\n");
    say(cap_name + " struts proudly.\n");
    return 1;
}

sulk() {
    if (ghost())
        return 0;
    write("You sulk.\n");
    say(cap_name + " sulks in the corner.\n");
    return 1;
}

taunt(str) {
    object who;
    if (ghost())
        return 0;
    if (str == 0)
        return 0;
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
        return 0;
    tell_object(who, cap_name + " really pisses you off.\n");
    say(cap_name + " taunts " + capitalize(str) + ".\n", who);
    write("You taunt " + capitalize(str) + ".\n");
    return 1;
}

thank(str) {
    object who;
    if (ghost())
        return 0;
    if (str == 0)
        return 0;
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
        return 0;
    write("You thank " + capitalize(str) + ".\n");
    say(cap_name + " thanks " + capitalize(str) + ".\n", who);
    tell_object(who, cap_name + " thanks you.\n");
    return 1;
}

think() {
    if (ghost())
        return 0;
    write("You start thinking serious matters of life.\n");
    say("Looks like " + cap_name + " started thinking something very hard.\n");
    return 1;
}

tickle(str) {
    object who;
    string target;
    if (ghost())
        return 0;
    if (str == 0)
        return 0;
    target = str;
    if (sscanf(str, "%s in the %s", target, bodypart)) {
        get_bodypart(bodypart); 
    }
    who = present(target, environment(this_player()));
    if (!who || !living(who) || who == this_player())
        return 0;
    if (!bodypart) {
        tell_object(who, cap_name + " tickles you gleefully.\n");
        say(cap_name + " tickles " + capitalize(target) + " gleefully.\n", who);
        write("You tickle " + capitalize(target) + " gleefully.\n");
    }
    else {
        tell_object(who, cap_name + " tickles you in the " + bodypart +
                ".\n");
        say(cap_name + " tickles " + capitalize(target) + " in the " +
                bodypart + ".\n", who);
        write("You tickle " + capitalize(target) + " in the " +
                bodypart + ".\n");
    }
    return 1;
}

tremble(str) {
    if (ghost())
        return 0;
    adverb = get_adverb(str);
    if (!adverb) { adverb = "fearfully"; }
    write("You tremble " + adverb + ".\n");
    say(cap_name + " trembles " + adverb + ".\n");
    return 1;
}

tsk() {
    if (ghost())
        return 0;
    write("Are you sure what you're doing?\n");
    say(cap_name + " goes 'tsk tsk' while acting like an animal.\n");
    return 1;
}

twiddle() {
    if (ghost())
        return 0;
    write("You twiddle your thumbs.\n");
    say(cap_name + " twiddles " + the_owner->query_possessive() +
        " thumbs.\n");
    return 1;
}

wait(str) {
    object who;
    if (ghost())
        return 0;
    if(!str) {
        write("You wait patiently.\n");
        say(cap_name + " waits patiently.\n");
        return 1;
    }
    who = present(lower_case(str), environment(this_player()));
    if (!who || !living(who) || who == this_player())
        return 0;
    tell_object(who, cap_name + " waits for you.\n");
    write("You wait for " + capitalize(str) +".\n");
    say(cap_name + " waits for " + capitalize(str) + ".\n", who);
    return 1;
}

wake(str) {
    object who;
    if (ghost())
    	return 0;
    if (str == 0)
    	return 0;
    who = present(str, environment(this_player()));
    if (!who || !living(who) || who == this_player())
        return 0;
    tell_object(who, cap_name + " attempts to wake you up by poking you in the rib.\n");
    say(cap_name + " tries to wake " + capitalize(str) + " up.\n", who);
    write("You try to wake " + capitalize(str) + " up.\n");
    return 1;
}
 
wave(str) {
    object who;
    if (ghost())
        r== this_player())
        return 0;
    tell_object(who, cap_name + " waves " + adverb + " at you.\n");
    write("You wave " + adverb + " at " + capitalize(str) +".\n");
    say(cap_name + " waves " + adverb + " at " + capitalize(str) + ".\n", who);
    return 1;
}

whine(str) {
    if (ghost())
        return 0;
    adverb = get_adverb(str);
    if (!adverb) { adverb = "endlessly"; }
    write("You whine " + adverb + ".\n");
    say(cap_name + " whines " + adverb + ".\n");
    return 1;
}

whistle(str) {
    object who;
    if (ghost())
        return 0;
    if(!str) {
        write("You whistle appreciatively.\n");
        say(cap_name + " whistles appreciatively.\n");
        return 1;
    }
    who = present(lower_case(str), environment(this_player()));
    if (!who || !living(who) || who == this_player())
        return 0;
    tell_object(who, cap_name + " whistles appreciatively at you.\n");
    write("You whistle appreciatively at " + capitalize(str) +".\n");
    say(cap_name + " whistles appreciatively at " + capitalize(str) + ".\n", who);
    return 1;
}

wiggle() {
    if (ghost())
        return 0;
    write("You wiggle your bottom.\n");
    say(cap_name + " wiggles " + the_owner->query_possessive() +
        " bottom.\n");
    return 1;
}

wink(str) {
    object who;
    if (ghost())
        return 0;
    if(!str) {
        write("You wink.\n");
        say(cap_name + " winks suggestively.\n");
        return 1;
    }
    who = present(lower_case(str), environment(this_player()));
    if (!who || !living(who) || who == this_player())
        return 0;
    tell_object(who, cap_name + " winks suggestively at you.\n");
    write("You wink at " + capitalize(str) +".\n");
    say(cap_name  immortals.\n");
        return 1;
    }
    who = present(lower_case(str), environment(this_player()));
    if (!who || !living(who) || who == this_player())
        return 0;
    tell_object(who, cap_name + " worships you.\n");
    write("You worship " + capitalize(str) +".\n");
    say(cap_name + " worships " + capitalize(str) + ".\n", who);
    return 1;
}

yawn() {
    if (ghost())
        return 0;
    write("My, what big teeth you have!\n");
    say(cap_name + " yawns.\n");
    return 1;
}

yodel(str) {
    if (ghost())
        return 0;
    adverb = get_adverb(str);
    if (!adverb) { adverb = "noisily"; }
    write("You yodel " + adverb + ".\n");
    say(cap_name + " yodels " + adverb + ".\n");
    return 1;
}
