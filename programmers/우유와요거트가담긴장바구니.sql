SELECT distinct cart_id
from cart_products
where lower(name) = 'milk' and cart_id in (select distinct cart_id
                                            from cart_products
                                            where lower(name) = 'yogurt');
                                            
/* yogurt나 milk를 이용객이 여러개 샀을 수 있으므로 distinct 추가 */