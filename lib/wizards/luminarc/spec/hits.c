object player;
int     hits;
int     value;
mapping my_map;
mapping check_hits;
mapping hit_me;
string  name;
int map_allocated_my_map = 0;
int map_allocated_check_hits = 0;
int map_allocated_hit_me = 0;
reset_my_map()
{
        map_allocated_my_map = 0;
return 1;
}

reset_check_hits()
{
        map_allocated_check_hits = 0;
return 1;
}
reset_hit_me()
{
        map_allocated_hit_me = 0;
return 1;
}
alloc_my_map()
{
        my_map = ([]);

        return 1;
}



alloc_check_hits()
{
        check_hits = ([]);

        return 1;
}



alloc_hit_me()
{
        hit_me = ([]);

        return 1;
}


snowball_hit(string player)
{

        if (map_allocated_my_map == 0)
                        {
                        map_allocated_my_map = alloc_my_map();
                        }
        my_map[player] = my_map[player]+1;
        return 1;
}



hits(string player)
{
        return my_map[player]; 
}



check_hits(string player)
{
        return hit_me[player];
}


hit_me(string player)
{
        if (map_allocated_hit_me == 0)
                {
                map_allocated_hit_me=alloc_hit_me();
                }
hit_me[player] = hit_me[player] + 1;

return 1;
}
