# down google img: (248 server)
cd /home/sdb1/xq/taiwan/data/object_detection/coco_wider_pedestrian/google_images
python Image-Downloader/image_downloader.py \
"garbage can" \
--max-number 10000 \
--output data_garbage_can \
--driver chrome_headless \
--timeout 500

上传，过模型

传回来，转labelme

传到本地，过一遍

传到data，划分数据集

转json，合并json