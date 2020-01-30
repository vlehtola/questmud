//This shadow keeps a necromancer's horde defending him -- Rag 3.2.2004
//Some minor adjustments and improvements -- Rag 20.2.2004

// implemented the "almost" invulnerabilty with randoms. 1.11.2005 Celtron

object necro;

start(obj,time) {
        if ( !obj ) return;
        necro = obj;
        shadow(necro, 1);
        call_out("end",time);
}

end() {
        tell_object(necro, "You fail to keep your horde defending you.\n");
        destruct(this_object());
}

hit_player(dam, type, arg1, arg2) {
        object horde;

        horde = get_horde();

        if ( horde && random(5) ) {
                tell_object(necro, "Your horde rushes to defend you!\n");
                horde->attack_ob(necro->query_attack_ob());
                return horde->hit_player(dam, type, arg1, arg2);
        }
        return necro->hit_player(dam, type, arg1, arg2);
}

hit_with_spell(dam, type, arg1, arg2) {
        object horde;
                                                                                                                 
        horde = get_horde();
                                                                                                                 
        if ( horde && random(5)) {
                tell_object(necro, "Your horde rushes to defend you!\n");
                horde->attack_ob(necro->query_attack_ob());
                return horde->hit_with_spell(dam, type, arg1, arg2);
        }
        return necro->hit_with_spell(dam, type, arg1, arg2);
}

set_stunned(arg1, arg2, arg3) {
        object horde;

        horde = get_horde();

        if ( horde ) {
                horde->attack_ob(necro->query_attack_ob());
                return horde->set_stunned(arg1, arg2, arg3);
        }
        return necro->set_stunned(arg1, arg2, arg3);
}

status is_horde(object ob) {
        return ob->query_necro_horde();
}

get_horde() {
        object *obs;
        int i;

        obs = all_inventory(environment(necro));
        obs = filter( obs,"is_horde");

        if ( !obs ) {
                end();
                return 0;
        }
        for ( i = 0; i < sizeof(obs); i++ ) {
                if ( obs[i]->query_horde_master() == lower_case(necro->query_name()) ) {
                        return obs[i];
                }
        }
        end();
        return 0;
}
