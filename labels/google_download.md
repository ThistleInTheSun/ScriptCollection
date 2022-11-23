# down google img: (248 server)
cd /home/sdb1/xq/taiwan/data/object_detection/coco_wider_pedestrian/google_images

cd /dataset/object_detection/coco_wider_pedestrian
python Image-Downloader/image_downloader.py \
"办公室椅子" \
--max-number 10000 \
--output data_ergonomic_chair1 \
--driver chrome_headless \
--timeout 500
