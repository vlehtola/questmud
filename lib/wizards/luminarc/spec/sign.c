mapping event_players;
int allocated_event_players=0;
int players = 1;
reset_event_players()
{
allocated_event_players=0;
return 1;
}
allocate_event_players()
{
        event_players = ([]);

        return 1;
}
sign_up(string player)
{
if (allocated_event_players==0)
        {
        allocated_event_players=allocate_event_players();
        }
event_players[players] = player;
players++;
return 1;
}
how_many_players()
{
        return players;
}

query_event_player(int x)
{
        if (x==0)
                x=1;
        return event_players[x];
}
reduce_players()
{
players--;
return 1;
}
