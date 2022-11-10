from __future__ import annotations

import os
from tqdm import tqdm
from random import shuffle
from shutil import copy


def split_trainval(path, train_path, val_path, img_type, rate):
    img_names = [x for x in os.listdir(path) if not x.endswith(".json")]
    shuffle(img_names)
    thr = int(len(img_names) * rate)
    # train
    for img_n in tqdm(img_names[:thr]):
        name = os.path.splitext(img_n)[0]
        src_img_path = os.path.join(path, img_n)
        tar_img_path = os.path.join(train_path, img_type + "_" + img_n)
        copy(src_img_path, tar_img_path)
        if os.path.exists(os.path.join(path, name + ".json")):
            src_path = os.path.join(path, name + ".json")
            tar_path = os.path.join(train_path, img_type + "_" + name + ".json")
            copy(src_path, tar_path)
    # val
    for img_n in tqdm(img_names[thr:]):
        name = os.path.splitext(img_n)[0]
        src_img_path = os.path.join(path, img_n)
        tar_img_path = os.path.join(val_path, img_type + "_" + img_n)
        copy(src_img_path, tar_img_path)
        if os.path.exists(os.path.join(path, name + ".json")):
            src_path = os.path.join(path, name + ".json")
            tar_path = os.path.join(val_path, img_type + "_" + name + ".json")
            copy(src_path, tar_path)
    

    
if __name__ == "__main__":
    fimes = dict(
        data_chair_clothes="chair_clothes",
        data_plants="plants",
        data_half_person_1="half_person",
        data_half_person_office="office_person",
        data_sideways_person="sideways_person",
        data_garbage_can="garbage_can",
        data_dog="dog",
        data_cat="cat",
        )
    root = "/home/sdb1/xq/taiwan/data/object_detection/coco_wider_pedestrian/google_images/corrected_label"
    train_path = "/home/sdb1/xq/taiwan/data/object_detection/coco_wider_pedestrian/google_images/train"
    val_path = "/home/sdb1/xq/taiwan/data/object_detection/coco_wider_pedestrian/google_images/val"
    rate = 0.667
    os.makedirs(train_path, exist_ok=True)
    os.makedirs(val_path, exist_ok=True)
    for dir_name, img_type in fimes.items():
        split_trainval(os.path.join(root, dir_name), train_path, val_path, img_type, rate)