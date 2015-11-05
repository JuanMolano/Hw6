field.pdf:	points.txt graph.py
	python graph.py

points.txt : particle_in_field
	./particle_in_field 100 100  > points.txt

particle_in_field : particle_in_field.c
	cc particle_in_field.c -o particle_in_field


