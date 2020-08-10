SELECT animal_id, name, to_char(datetime, 'yyyy-MM-dd') 
from animal_ins
order by animal_id asc;