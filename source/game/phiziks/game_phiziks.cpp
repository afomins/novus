


#include	"main\main.h"
#include	"game\game.h"
#include	"timer\timer.h"

#include	<math.h>

bool		friendly_fire	= false;
bool		success			= false;
bool		main_in_hole	= false;

void	game_phiziks_process()
{
	unsigned short		loop_player;
	unsigned short		loop_puck;

	unsigned short		old_player;
	unsigned short		new_player;

	g_game.game_motion_on			= false;
	g_game.player_puck_min_speed	= g_game.player[g_game.player_active].puck[0].motion_speed;

	//	***	[	CHECK_MOTION	]
	for(loop_player = 0; loop_player < PLAYER_MAX_NUM; loop_player++)
	{
		if(g_game.player[loop_player].player_on)
		{
			for(loop_puck = 0; loop_puck < PUCK_MAX_NUM; loop_puck++)
			{
				if(g_game.player[loop_player].puck[loop_puck].puck_on)
				{
					if(g_game.player[loop_player].puck[loop_puck].motion_speed > g_game.player_puck_min_speed)
					{
						g_game.player_puck_min_speed	= g_game.player[loop_player].puck[loop_puck].motion_speed;
					}

					if(g_game.player[loop_player].puck[loop_puck].motion_speed < 0.01)	
					{
						g_game.player[loop_player].puck[loop_puck].motion_speed = 0.0;
					}

					if(g_game.player[loop_player].puck[loop_puck].motion_speed != 0.0)	
					{
						g_game.game_motion_on	= true;
					}
				}
			}
		}
	}

	if(!g_game.game_motion_on)	
	{
		unsigned short	loop_player;
		unsigned short	loop_puck;

		if(friendly_fire)
		{
			for(loop_player = 0; loop_player < PLAYER_MAX_NUM; loop_player++)
			{
				if(g_game.player[loop_player].player_on)
				{
					for(loop_puck = 1; loop_puck < PUCK_MAX_NUM; loop_puck++)
					{
						g_game.player[loop_player].puck[loop_puck].coord		= g_game.player[loop_player].puck[loop_puck].coord_old;
						g_game.player[loop_player].puck[loop_puck].puck_on		= g_game.player[loop_player].puck[loop_puck].puck_on_old;
					}
				}
			}

			if(!main_in_hole)					g_game.player[g_game.player_active].score--;

			main_in_hole	= false;
		}

		if((friendly_fire) || (!success))
		{
			old_player	= g_game.player_active;
			new_player	= g_game.player[old_player].player_next;

			g_game.player[old_player].puck[0].puck_on	= false;
		}
		else
		{
			new_player	= g_game.player_active;
		}

		//	***	[	end game]

		game_check_end_game();

		if(!g_game.game_on)		return;

		//	***

		g_game.player_active			= new_player;
		g_game.game_camera_script_on	= true;


		g_game.player[new_player].puck[0].puck_on	= true;
		g_game.player[new_player].puck[0].coord_new.x	= g_game.player[new_player].camera_start.center_x;
		g_game.player[new_player].puck[0].coord_new.y	= g_game.player[new_player].camera_start.center_y;
		g_game.player[new_player].puck[0].coord_new.z	= g_game.player[new_player].camera_start.center_z;

		g_game.player[new_player].puck[0].coord.x		= g_game.player[new_player].camera_start.center_x;
		g_game.player[new_player].puck[0].coord.y		= g_game.player[new_player].camera_start.center_y;
		g_game.player[new_player].puck[0].coord.z		= g_game.player[new_player].camera_start.center_z;

		g_game.player[new_player].camera_start.radius		= camera.rotate.radius;
		g_game.player[new_player].camera_start.angle_v		= camera.rotate.angle_v;

		g_game.camera_properties.script.next_camera_mode	= CAMERA_MODE_ROTATE;

		g_game.camera_properties.script.script_length		= camera.camera_script_length_default;

		g_game.camera_properties.script.end_angle_h			= g_game.player[new_player].camera_start.angle_h + PI;
		g_game.camera_properties.script.end_angle_v			= -g_game.player[new_player].camera_start.angle_v;
		g_game.camera_properties.script.end_x				= g_game.player[new_player].camera_start.center_x + cos(g_game.player[new_player].camera_start.angle_h) * cos(g_game.player[new_player].camera_start.angle_v) * g_game.player[new_player].camera_start.radius;
		g_game.camera_properties.script.end_z				= g_game.player[new_player].camera_start.center_z + sin(g_game.player[new_player].camera_start.angle_h) * cos(g_game.player[new_player].camera_start.angle_v) * g_game.player[new_player].camera_start.radius;
		g_game.camera_properties.script.end_y				= g_game.player[new_player].camera_start.center_y + sin(g_game.player[new_player].camera_start.angle_v) * g_game.player[new_player].camera_start.radius;

		g_game.camera_properties.script.start_angle_h		= camera.rotate.angle_h + PI;
		g_game.camera_properties.script.start_angle_v		= -camera.rotate.angle_v;
		g_game.camera_properties.script.start_x				= camera.rotate.center_x + cos(camera.rotate.angle_h) * cos(camera.rotate.angle_v) * camera.rotate.radius;
		g_game.camera_properties.script.start_z				= camera.rotate.center_z + sin(camera.rotate.angle_h) * cos(camera.rotate.angle_v) * camera.rotate.radius;
		g_game.camera_properties.script.start_y				= camera.rotate.center_y + sin(camera.rotate.angle_v) * camera.rotate.radius;

		camera_script_create(g_game.camera_properties.script);
		camera_rotate_create(g_game.player[new_player].camera_start);

		camera.camera_mode	= CAMERA_MODE_SCRIPT;

		friendly_fire	= false;
		success			= false;

		return; 
	}

	game_phiziks_puck_hole_collision_process();
	game_phiziks_puck_to_border_collision_process();
	game_phiziks_puck_to_puck_collision_process();
	game_phiziks_puck_speed_process();	
}

void	game_phiziks_push_puck(unsigned short player_id, unsigned short puck_id, float angle, float push_strength)
{
	if(angle > 2 * PI)	angle	-= 2 * PI;
	if(angle < 0)		angle	+= 2 * PI;

	g_game.game_motion_on									= true;
	g_game.player[player_id].puck[puck_id].motion_angle		= angle;
	g_game.player[player_id].puck[puck_id].motion_speed		= (float)push_strength * 0.1 * 0.8;
	g_game.player_puck_max_speed							= push_strength;

	unsigned short	loop_player;
	unsigned short	loop_puck;

	for(loop_player = 0; loop_player < PLAYER_MAX_NUM; loop_player++)
	{
		if(g_game.player[loop_player].player_on)
		{
			for(loop_puck = 1; loop_puck < PUCK_MAX_NUM; loop_puck++)
			{
				g_game.player[loop_player].puck[loop_puck].coord_old	= g_game.player[loop_player].puck[loop_puck].coord;
				g_game.player[loop_player].puck[loop_puck].puck_on_old	= g_game.player[loop_player].puck[loop_puck].puck_on;
			}
		}
	}
}

void	game_phiziks_puck_speed_process()
{
	unsigned short		loop_player;
	unsigned short		loop_puck;
	float				angle;
	float				speed;

	for(loop_player = 0; loop_player < PLAYER_MAX_NUM; loop_player++)
	{
		if(g_game.player[loop_player].player_on)
		{
			for(loop_puck = 0; loop_puck < PUCK_MAX_NUM; loop_puck++)
			{
				if(g_game.player[loop_player].puck[loop_puck].puck_on)	
				{
					speed	= g_game.player[loop_player].puck[loop_puck].motion_speed;
					angle	= g_game.player[loop_player].puck[loop_puck].motion_angle;

					g_game.player[loop_player].puck[loop_puck].motion_speed	-= g_game.player[loop_player].puck[loop_puck].motion_speed * 0.04;

//					g_game.player[loop_player].puck[loop_puck].coord	= g_game.player[loop_player].puck[loop_puck].coord_new;
//					g_game.player[loop_player].puck[loop_puck].coord	= g_game.player[loop_player].puck[loop_puck].coord_new;

//					g_game.player[loop_player].puck[loop_puck].coord_new.x		+= cos(angle) * speed;
//					g_game.player[loop_player].puck[loop_puck].coord_new.z		+= sin(angle) * speed;

					g_game.player[loop_player].puck[loop_puck].coord.x			+= cos(angle) * speed;
					g_game.player[loop_player].puck[loop_puck].coord.z			+= sin(angle) * speed;

				}
			}
		}
	}
}

void	game_phiziks_puck_to_border_collision_process()
{
	unsigned short		loop_player;
	unsigned short		loop_puck;
	float				radius;
	float				w1	= g_game.model_table_plane_properties.width;
	float				w2	= g_game.model_table_plane_properties.side_width;
	game_puck_instance	*puck;

	for(loop_player	= 0; loop_player	< PLAYER_MAX_NUM; loop_player++)
	{
		if(g_game.player[loop_player].player_on)
		{
			for(loop_puck	= 0; loop_puck	< PUCK_MAX_NUM; loop_puck++)
			{
				if(g_game.player[loop_player].puck[loop_puck].puck_on)
				{
					puck	= &g_game.player[loop_player].puck[loop_puck];
					radius	= g_game.model_puck_properties[puck->puck_type].radius;

					if(puck->coord.x > w1 +w2 -radius)
					{
						puck->coord.x		= w1 +w2 -radius;
						puck->motion_angle	= PI -puck->motion_angle;
						puck->motion_speed	*= 0.6;
					}

					if(puck->coord.x < -w1 -w2 +radius)
					{
						puck->coord.x		= -w1 -w2 +radius;
						puck->motion_angle	= PI -puck->motion_angle;
						puck->motion_speed	*= 0.6;
					}

					if(puck->coord.z > w1 +w2 -radius)
					{
						puck->coord.z		= w1 +w2 -radius;
						puck->motion_angle	= -puck->motion_angle;
						puck->motion_speed	*= 0.6;
					}

					if(puck->coord.z < -w1 -w2 +radius)
					{
						puck->coord.z		= -w1 -w2 +radius;
						puck->motion_angle	= -puck->motion_angle;
						puck->motion_speed	*= 0.6;
					}
				}
			}
		}
	}
}

void	game_phiziks_puck_to_puck_collision_process()
{
	unsigned short	main_player;
	unsigned short	main_puck;
	float			main_radius;

	unsigned short	hit_player;
	unsigned short	hit_puck;
	float			hit_radius;

	float			puck_distance;
	float			puck_x;
	float			puck_z;
	float			puck_angle;

	game_puck_instance	*p_main;
	game_puck_instance	*p_hit;

	//	***	[	MAIN ]
	for(main_player = 0; main_player < PLAYER_MAX_NUM; main_player++)
	{
		if(g_game.player[main_player].player_on)
		{
			for(main_puck = 0; main_puck < PUCK_MAX_NUM; main_puck++)
			{
				p_main			= &g_game.player[main_player].puck[main_puck];

				if((g_game.player[main_player].puck[main_puck].puck_on) &&
				   (p_main->motion_speed != 0.0))
				{
					main_radius		= g_game.model_puck_properties[p_main->puck_type].radius;
					
					//	***	[	HIT ]
					for(hit_player = 0; hit_player < PLAYER_MAX_NUM; hit_player++)
					{
						if(g_game.player[hit_player].player_on)
						{
							for(hit_puck = 0; hit_puck < PUCK_MAX_NUM; hit_puck++)
							{
								p_hit			= &g_game.player[hit_player].puck[hit_puck];

								if((g_game.player[hit_player].puck[hit_puck].puck_on) &&
								   (p_main != p_hit) &&
								   (p_main->motion_speed > p_hit->motion_speed))
								{
									p_hit			= &g_game.player[hit_player].puck[hit_puck];
									hit_radius		= g_game.model_puck_properties[p_hit->puck_type].radius;

									puck_x			= p_hit->coord.x - p_main->coord.x;
									puck_z			= p_hit->coord.z - p_main->coord.z;

									puck_distance	= sqrt(puck_x * puck_x + puck_z * puck_z);

									if(puck_distance < main_radius + hit_radius)
									{
										float	x		= puck_x;
										float	z		= puck_z;

										if(x < 0)	x *= -1;
										if(z < 0)	z *= -1;

										puck_angle	=	asin(z / puck_distance);
	
										if((puck_x < 0) && (puck_z < 0))
										{
											puck_angle	+= PI;
										}
										else
										if((puck_x < 0) && (puck_z > 0))
										{
											puck_angle	= PI - puck_angle;
										}
										else
										if((puck_x > 0) && (puck_z < 0))
										{
											puck_angle	= 2 * PI - puck_angle;
										}
										
										p_hit->motion_angle					= (puck_angle + p_main->motion_angle) / 2.0;
//										p_hit->motion_angle					= puck_angle;

										if(p_hit->motion_angle > 2 * PI)	p_hit->motion_angle	-= 2 * PI;

										if(p_main->motion_angle > puck_angle)
										{
											p_main->motion_angle	= p_hit->motion_angle + (p_main->motion_angle - puck_angle);//PI / 2;

											if(p_main->motion_angle >  2 * PI)	p_main->motion_angle -=  2 * PI;
										}
										else
										if(p_main->motion_angle < puck_angle)
										{
											p_main->motion_angle	= p_hit->motion_angle - (puck_angle - p_main->motion_angle);//PI / 2;

											if(p_main->motion_angle <  0)	p_main->motion_angle +=  2 * PI;
										}

										p_main->motion_speed				*= 0.5;
										p_hit->motion_speed					= p_main->motion_speed * 1.2;
										
										p_hit->coord.x	+= cos(puck_angle) * (main_radius +hit_radius -puck_distance) * 2;
										p_hit->coord.z	+= sin(puck_angle) * (main_radius +hit_radius -puck_distance) * 2;
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

void	game_phiziks_puck_hole_collision_process()
{
	unsigned short		loop_player;
	unsigned short		loop_puck;
	unsigned short		loop_hole;

	float				diag;

	game_coord_instance	*puck;
	game_coord_instance	*hole;

	float				kat_x;
	float				kat_z;

	float				width	= g_game.model_table_plane_properties.width;

	unsigned short		puck_type;
	float				puck_radius;
	float				hole_radius	= g_game.model_table_plane_properties.hole_radius;;


	for(loop_player = 0; loop_player < 4; loop_player++)
	{
		if(g_game.player[loop_player].player_on)
		{
			for(loop_puck = 0; loop_puck < PUCK_MAX_NUM; loop_puck++)
			{
				puck	= &g_game.player[loop_player].puck[loop_puck].coord;

				if(	(g_game.player[loop_player].puck[loop_puck].puck_on) &&
					
					((puck->x > width) || (puck->x < -width) || 
					(puck->z > width)  || (puck->z < -width)))
				{
					for(loop_hole = 0; loop_hole < 4; loop_hole++)
					{
						hole		= &g_game.model_table_plane_properties.hole[loop_hole];
						puck_type	= g_game.player[loop_player].puck[loop_puck].puck_type;
						puck_radius	= g_game.model_puck_properties[puck_type].radius;

						kat_x	= hole->x - puck->x;
						kat_z	= hole->z - puck->z;

						diag	= sqrt(kat_x * kat_x + kat_z * kat_z);

						float_temp	= diag;

						if(puck_radius + hole_radius > diag)
						{
							success	= true;

							g_game.player[loop_player].puck[loop_puck].puck_on		= false;
							g_game.player[loop_player].puck[loop_puck].motion_speed	= 0.0;

							if(g_game.player[loop_player].team == g_game.player[g_game.player_active].team)
							{
								friendly_fire	= true;
							}

							if((!friendly_fire) && (loop_puck != 0))
							{
								g_game.player[g_game.player_active].score++;
							}

							if((friendly_fire) && (loop_puck == 0))
							{
								main_in_hole	= true;
							}
						}
					}
				}
			}
		}
	}
}

void	game_phiziks_aim_process()
{

	g_game.aim_angle[0]	= camera.rotate.angle_h + PI;
	g_game.aim_start[0]	= g_game.player[g_game.player_active].puck[0].coord;
/*
	g_game.aim_total_length				= g_game.player_push_strength / 2.0;

	float					w			= g_game.model_table_plane_properties.width + g_game.model_table_plane_properties.side_width;
	float					c_length	= g_game.aim_total_length;
	float					c_angle		= camera.rotate.angle_h + PI;
	game_coord_instance		c_coord		= g_game.player[g_game.player_active].puck[0].coord;
	unsigned short	loop;

	g_game.aim_on[0]	= false;
	g_game.aim_on[1]	= false;
	g_game.aim_on[2]	= false;

	for(loop = 0; loop < 1; loop++)
	{
		START:

		if(	(c_angle > 0.0) &&
			(c_angle < PI / 2))
		{
			g_game.aim_angle[loop]	= c_angle;
			g_game.aim_on[0]		= true;

			if(	(c_coord.x + cos(c_angle) * c_length) > w)
			{
				g_game.aim_length[loop]	=	(w - c_coord.x) / (float)cos(c_angle);

				c_coord.x	= w;
				c_coord.z	+=  sin(c_angle) * g_game.aim_length[loop];

				c_length	-= g_game.aim_length[loop];
				c_angle		=  PI - c_angle;

				goto	START;
			}
		}
	}
*/
}

