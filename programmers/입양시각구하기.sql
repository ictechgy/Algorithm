SELECT to_char(datetime, 'hh24') hour, count(*) count
from animal_outs
group by to_char(datetime, 'hh24')
having to_char(datetime, 'hh24') between 9 and 19       /* 또는 아예 where 조건절을 이용하여 필요한 레코드를 먼저 추출하여도 될 것 같다. 그게 더 빠를 듯 */
order by hour asc;