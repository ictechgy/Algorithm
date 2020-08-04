SELECT animal_type, count(*)
from animal_ins
group by animal_type
having lower(animal_type) in ('cat', 'dog')
order by animal_type asc;   /*실질적으로는 없어도 되는 부분*/