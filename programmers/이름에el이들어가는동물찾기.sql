SELECT animal_id, name
from (select animal_id, name
        from animal_ins
        where lower(animal_type) = 'dog')
where lower(name) like '%el%'
order by name asc;

/*또는*/

SELECT animal_id, name
from animal_ins
where lower(name) like '%el%' and lower(animal_type) = 'dog'
order by name asc;

/*다만 테이블의 크기가 커지면 dog타입과 el이름이 들어가는 동물을 교집합으로 찾는 아래방법보다는 위의 방법이 더 빠를 것*/