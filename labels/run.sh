# coco2labelme
name_list=("data_half_person_1" \
            "data_half_person_office" \
            "data_plants" \
            "data_sideways_person")

for name in ${name_list[*]};  
do  
name="data_chair_clothes"
python /home/sdb1/xq/eval_data/coco2labelme.py \
--j /home/sdb1/xq/taiwan/data/object_detection/coco_wider_pedestrian/google_images/${name}.json \
--i /home/sdb1/xq/taiwan/data/object_detection/coco_wider_pedestrian/google_images/${name} \
--s /home/sdb1/xq/taiwan/data/object_detection/coco_wider_pedestrian/google_images/${name}_labelme;
done  


